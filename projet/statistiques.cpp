#include "statistiques.h"
#include "ui_statistiques.h"
#include <QSound>
statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
    statistiques::makePlot();
}

statistiques::~statistiques()
{
    delete ui;
}

void statistiques::makePlot()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(4, 43, 84));
    gradient.setColorAt(0.38, QColor(0, 102, 204));
    gradient.setColorAt(1, QColor(4, 43, 84));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:

    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);


    fossil->setAntialiased(false);

    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Fossil fuels");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));




    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;
    labels << "France" << "spain" << "usa" << "china"  << "italy" << "turkey" << "mexico" << "germany " << "thailand" << "uk";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(45);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 11);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:


    ui->customPlot->yAxis->setRange(0, 100);
    ui->customPlot->yAxis->setPadding(50); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("pourcentage des billets reserver");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
//nombre des billets reserver pour chaque country
    QSqlQuery q;
    QString usa="usa";
    QString nv="non valable";
     q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+usa+"')and(etat='"+nv+"'))"));
     q.exec();
     int nbusa= 0;
     if (q.next()) {
            nbusa= q.value(0).toInt();
             qDebug()<<"nombre des billet reserver usa"<<nbusa;
     }

     QString france="france";
      q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+france+"')and(etat='"+nv+"'))"));
      q.exec();
      int nbfrance= 0;
      if (q.next()) {
             nbfrance= q.value(0).toInt();
              qDebug()<<"nombre des billet reserver france"<<nbfrance;
      }

      QString china="china";
       q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+ china+"')and(etat='"+nv+"'))"));
       q.exec();
       int nbchina= 0;
       if (q.next()) {
              nbchina= q.value(0).toInt();
               qDebug()<<"nombre des billet reserver  china"<<nbchina;
       }

       QString spain="spain";
        q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+spain+"')and(etat='"+nv+"'))"));
        q.exec();
        int nbspain= 0;
        if (q.next()) {
               nbspain= q.value(0).toInt();
                qDebug()<<"nombre des billet reserver  spain"<<nbspain;
        }

        QString italy="italy";
         q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+italy+"')and(etat='"+nv+"'))"));
         q.exec();
         int nbitaly= 0;
         if (q.next()) {
                nbitaly= q.value(0).toInt();
                 qDebug()<<"nombre des billet reserver  italy"<<nbitaly;
         }

         QString turkey="turkey";
          q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+turkey+"')and(etat='"+nv+"'))"));
          q.exec();
          int nbturkey= 0;
          if (q.next()) {
                 nbturkey= q.value(0).toInt();
                  qDebug()<<"nombre des billet reserver  turkey"<<nbturkey;
          }

          QString mexico="mexico";
           q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+mexico+"')and(etat='"+nv+"'))"));
           q.exec();
           int nbmexico= 0;
           if (q.next()) {
                  nbmexico= q.value(0).toInt();
                   qDebug()<<"nombre des billet reserver  mexico"<<nbmexico;
           }


           QString germany="germany";
            q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+germany+"')and(etat='"+nv+"'))"));
            q.exec();
            int nbgermany= 0;
            if (q.next()) {
                   nbgermany= q.value(0).toInt();
                    qDebug()<<"nombre des billet reserver  germany"<<nbgermany;
            }

            QString thailand="thailand";
             q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+thailand+"')and(etat='"+nv+"'))"));
             q.exec();
             int nbthailand= 0;
             if (q.next()) {
                    nbthailand= q.value(0).toInt();
                     qDebug()<<"nombre des billet reserver  thailand"<<nbthailand;
             }


             QString uk="uk";
              q.prepare(QString("SELECT COUNT (*) FROM BILLETS where((destination='"+uk+"')and(etat='"+nv+"'))"));
              q.exec();
              int nbuk= 0;
              if (q.next()) {
                     nbuk= q.value(0).toInt();
                      qDebug()<<"nombre des billet reserver  uk"<<nbuk;
              }


//nombre des billet reserved



               q.prepare(QString("SELECT COUNT (*) FROM BILLETS where etat='"+nv+"'"));
               q.exec();
               int nbillet= 0;
               if (q.next()) {
                      nbillet= q.value(0).toInt();
                       qDebug()<<"nombre des billet reserver "<<nbillet;
               }

//calcule de pourcentage
double pfrance;
pfrance=((nbfrance*1.0/nbillet*1.0)*100);

double pusa;
pusa=((nbusa*1.0/nbillet*1.0)*100);

double pitaly;
pitaly=((nbitaly*1.0/nbillet*1.0)*100);

double pspain;
pspain=((nbspain*1.0/nbillet*1.0)*100);

double pchina;
pchina=((nbchina*1.0/nbillet*1.0)*100);

double pmexico;
pmexico=((nbmexico*1.0/nbillet*1.0)*100);

double pturkey;
pturkey=((nbturkey*1.0/nbillet*1.0)*100);


double pgermany;
pgermany=((nbgermany*1.0/nbillet*1.0)*100);


double pth;
pth=((nbthailand*1.0/nbillet*1.0)*100);

double puk;
puk=((nbuk*1.0/nbillet*1.0)*100);
qDebug()<<"pourcent france "<<pfrance;

    // Add data:
    QVector<double> fossilData;
    fossilData  << pfrance << pspain << pusa << pchina << pitaly << pturkey << pmexico << pgermany << pth << puk;

    fossil->setData(ticks, fossilData);



}
