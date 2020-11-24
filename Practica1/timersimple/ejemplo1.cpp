#include "ejemplo1.h"


ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));

    connect(faster_button, SIGNAL(clicked()), this, SLOT(faster()) );
    connect(slower_button, SIGNAL(clicked()), this, SLOT(slower()) );
    connect(get_period, SIGNAL(clicked()), this, SLOT(show_period()) );

	
	mytimer.connect(std::bind(&ejemplo1::cuenta, this));
    mytimer.start(500);
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
	static bool stopped = false;
	stopped = !stopped;
	if(stopped)
		mytimer.stop();
	else
		mytimer.start(500);
	qDebug() << "click on button";
}

void ejemplo1::faster()
{
    mytimer.setPeriod(250);
}

void ejemplo1::slower()
{
    mytimer.setPeriod(1000);
}

void ejemplo1::show_period()
{
    int p;

    mytimer.getPeriod(p);
    lcdPeriod->display(p);
}

void ejemplo1::cuenta()
{
    lcdNumber->display(++cont);
	trick++;
}

