#include "TUIOSender.h"
#include "tangible_type.h"
#include <iostream>

static bool Verbose = false ;

TUIOSender::TUIOSender( MainWindowImpl *win)
{
	
	mywin = win ;
	fseq = 0 ;
	lastSpeed = 0.0 ;
	transmitSocket = NULL;
	
	

	
}

TUIOSender::~TUIOSender()
{
	delete transmitSocket;
}

void TUIOSender::connectSocket(std::string ip_address, int port)
{
	transmitSocket = new UdpTransmitSocket( IpEndpointName( ip_address.c_str(), port ) );
	printf("Socket Initialized : %s Port : %i\n\n", ip_address.c_str(), port);
	fseq = 0;
}

void TUIOSender::resetTx()
{
	char qbuffer[OUTPUT_BUFFER_SIZE]; // for alive and fseq message
	osc::OutboundPacketStream q( qbuffer, OUTPUT_BUFFER_SIZE );
	q.Clear();
	q << osc::BeginBundle();
	q << osc::BeginMessage( "/tuio/2Dcur" ) << "alive" << osc::EndMessage;
	q << osc::BeginMessage( "/tuio/2Dobj" ) << "alive" << osc::EndMessage;
	q << osc::EndBundle;
	if(q.IsReady())
		transmitSocket->Send( q.Data(), q.Size() );
}

void TUIOSender::frame()
{

	if(!transmitSocket)
	{
		std::cout << "Socket Not Initialized " << "\n" ;
		return;
	}
	
	int currentTime = mywin->t.elapsed() ;
	int dt = lastTime - currentTime ;
	lastTime = currentTime ;
	
	char pbuffer[OUTPUT_BUFFER_SIZE]; // for set messages 
	char qbuffer[OUTPUT_BUFFER_SIZE]; // for alive and fseq message
	char qObjbuffer[OUTPUT_BUFFER_SIZE]; // for alive and fseq message
	osc::OutboundPacketStream p( pbuffer, OUTPUT_BUFFER_SIZE );
	osc::OutboundPacketStream q( qbuffer, OUTPUT_BUFFER_SIZE );
	osc::OutboundPacketStream qObj( qObjbuffer, OUTPUT_BUFFER_SIZE );
	
	p.Clear();
	p << osc::BeginBundle();
	
	q.Clear();
	q << osc::BeginBundle();
	qObj.Clear();
	qObj << osc::BeginBundle();
	
		q << osc::BeginMessage( "/tuio/2Dcur" ) << "alive" ;
		qObj << osc::BeginMessage( "/tuio/2Dobj" ) << "alive" ;
	
	if (Verbose) std::cout << "Table is active \t" << mywin->table->OSCdata->active<<"\n" ;

	if (mywin->table->OSCdata->active )
	{
		
		TouchData *d = mywin->table->OSCdata ;
		
		if (mywin->table->OSCdata->packetUpdate)
		{
			float dx = d->X - d->LX ;
			float dy = d->Y - d->LY ;
			float m = sqrtf((dx*dx) + (dy*dy));
			p << osc::BeginMessage( "/tuio/2Dcur" ) << "set" << d->ID << (d->X)/600 << (d->Y)/400 << dx/600 << dy/400 << m << osc::EndMessage;
			d->LX = d->X ;
			d->LY = d->Y ;
			if (Verbose) std::cout << "Table Crsor set" << "\n" ;
			mywin->table->OSCdata->packetUpdate = false ;
		}
		
		q << d->ID ;
	
	
		
	}
	
	
	
	QList<QGraphicsItem *> list = mywin->scene->items(5,5,600,400,Qt::IntersectsItemShape);
	
	while (!(list.isEmpty()))
	{
		QGraphicsItem *localItem = list.takeFirst();

		Tangible_Type *myTangible = dynamic_cast<Tangible_Type*>(localItem);
		if ( !myTangible )
			continue;
		TouchData *d = myTangible->OSCdata ;
		
		if (Verbose) std::cout << "Packet Update" << d->packetUpdate << "\n" ;
		if ( d->packetUpdate )
		{
			float dx = d->X - d->LX ;
			float dy = d->Y - d->LY ;
			float m = sqrtf((dx*dx) + (dy*dy));
			if ( myTangible->tangible_type == 3 )
			{
				p << osc::BeginMessage( "/tuio/2Dcur" ) ;
				p << "set" << d->ID << (d->X)/600 << (d->Y)/400 << dx << dy << m << osc::EndMessage;
				if (Verbose) std::cout << "Animation Cursor Set  " << "\n" ;
			}
			else if ( myTangible->tangible_type == 1 || myTangible->tangible_type == 2 )
			{
				float n = 0 ;
				float speed = m/dt;
				float accel = (speed - lastSpeed)/dt ;
				lastSpeed = speed ; 
				float newm = sqrtf(m/2);
				//qDebug() << newm << endl ;

				p << osc::BeginMessage( "/tuio/2Dobj" ) ;
				p << "set" << d->ID  << d->tagID << (d->X)/600 << (d->Y)/400 << n << newm << newm << n  << accel << n << osc::EndMessage;
				if (Verbose) std::cout << "Animation Object Set  " << "\n" ;
			}
			
			d->LX = d->X ;
			d->LY = d->Y ;
			d->packetUpdate = false ;
		}
		
			if ( myTangible->tangible_type == 3 )
			{
				//q << osc::BeginMessage( "/tuio/2Dcur" ) ;
				q << d->ID ;
							
			}
			else if ( myTangible->tangible_type == 1 || myTangible->tangible_type == 2  )
			{
				qObj <<  d->ID ;
				
			}
			
			
		
	}
	
	q << osc::EndMessage;
	qObj << osc::EndMessage;
		
	
	fseq++;
	
	p << osc::BeginMessage( "/tuio/2Dcur" ) << "fseq" << fseq << osc::EndMessage;
	p << osc::EndBundle;
	q << osc::EndBundle;
		
	//std::cout << "P is ready " << p.IsReady() << "\n" ;
	//std::cout << "Q is ready " << q.IsReady() << "\n" ;
	
	if(q.IsReady())
		transmitSocket->Send( q.Data(), q.Size() );
		
	if(p.IsReady())
		transmitSocket->Send( p.Data(), p.Size() );

	
	
}
