#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
    connect(&timer, SIGNAL(timeout()), this, SLOT(count()));
    connect(faster_button, SIGNAL(clicked()), this, SLOT(faster()) );
    connect(slower_button, SIGNAL(clicked()), this, SLOT(slower()) );
    timer.start(1000);
    number = 0;
}

void ejemplo1::doButton()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(1000);
	qDebug() << "click on button";
}

void ejemplo1::count()
{
    lcdNumber->display(number);
    number ++;
    qDebug() <<"Tick";
}

void ejemplo1::faster()
{
    timer.setInterval(200);
}

void ejemplo1::slower()
{
    timer.setInterval(2000);
}


