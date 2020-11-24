#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include <chrono>
#include "timer.h"


class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT
    public:
        ejemplo1();
        virtual ~ejemplo1();
    
    public slots:
	void doButton();
    void faster();
    void slower();
    void show_period();
        
    private:
        Timer mytimer, mytimerLong;
        int cont = 0;
		
		// dos callbacks con diferente número de parámetros
        void cuenta();
		
		int trick = 5;
};

#endif // ejemplo1_H
