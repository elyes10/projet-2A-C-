#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "employer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refresh();
    connect(ui->sendBtn_3, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn_3, SIGNAL(clicked()),this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sendMail()
{
Smtp* smtp = new Smtp(ui->uname_3->text(), ui->paswd_3->text(), ui->server_3->text(), ui->port_3->text().toUShort());
connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


smtp->sendMail(ui->uname_3->text(), ui->rcpt_3->text() , ui->subject_3->text(),ui->msg_3->toPlainText());
}

void MainWindow::mailSent(QString status)
{
if(status == "Message sent")
    QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::refresh()
{
  ui->tabemployer->setModel(tmpemployer.afficher_employer());
  ui->comboBox_3->setModel(tmpemployer.afficher_list());
  ui->comboBox_5->setModel(tmpemployer.afficher_list());
  ui->tabconge->setModel(tmpconge.afficher_conge());
  ui->comboBox_4->setModel(tmpconge.afficher_list());
  ui->comboBox_6->setModel(tmpconge.afficher_list());
}

void MainWindow::on_ajouter_clicked()
{
    QString cin=ui->cin->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int age=ui->age->text().toInt();
    QString matricule=ui->matricule->text();
    int num_contrat=ui->numcontart->text().toInt();
    employer e(cin,nom,prenom,matricule,age,num_contrat);
    bool test=e.ajouter_employer();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " employer ajouté");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", " employer non ajouté ");
    }


    ui->tabemployer->setModel(tmpemployer.afficher_employer());
    refresh();
}



void MainWindow::on_supprimer_clicked()
{
    QString cin = ui->sup->text();
     employer e;
     e.setcin(cin);
     bool test=e.supprimer_employer();
     if(test)
     {   refresh();
         QMessageBox::information(this, "PAS D'ERREUR", "employer supprimé");
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "employer supprimé ");
     }

    ui->sup->clear();

}



void MainWindow::on_modifier_2_clicked()
{
    tmpemployer.setnom(ui->nom_4->text());
    tmpemployer.setprenom(ui->prenom_4->text());
    tmpemployer.setmatricule(ui->matricule_4->text());
    tmpemployer.setage(ui->age_4->text().toInt());
    tmpemployer.setnumcontrat(ui->num_contrat->text().toInt());

    bool test=tmpemployer.modifier_employer();
    if(test){
            QMessageBox::information(this, "PAS D'ERREUR", " conge modifié");
        }
        else
        {
            QMessageBox::critical(this, " ERREUR ", "conge non modifié ");
        }
    refresh();

}



void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmpemployer.setcin(arg1);
    tmpemployer.chercher();
    ui->nom_4->setText(tmpemployer.getnom());
    ui->prenom_4->setText(tmpemployer.getprenom());
    ui->matricule_4->setText(tmpemployer.getmatricule());
    ui->age_4->setText(QString::number(tmpemployer.getage()));
    ui->num_contrat->setText(QString::number(tmpemployer.getnumcontrat()));
    refresh();


}

void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);

}



void MainWindow::on_lineEdit_19_textChanged(const QString &arg1)
{
    ui->tabemployer->setModel(tmpemployer.recherche(arg1,etat));
    valeur=arg1;

}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabemployer->setModel(tmpemployer.recherche(valeur,etat));

}

//conge

void MainWindow::on_ajouter_2_clicked()
{   QString num_conge=ui->num_conge->text();
    QString date_debut=ui->date_debut->text();
    QString date_fin=ui->date_fin->text();
    QString type=ui->type_3->text();
    QString cin_employer=ui->cine->text();

    conge g(num_conge,date_debut,date_fin,type,cin_employer);
    bool test=g.ajouter_conge();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " conge ajouté");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", "conge non ajouté ");
    }


    ui->tabconge->setModel(tmpconge.afficher_conge());
    refresh();

}

void MainWindow::on_supprimer_2_clicked()
{

    QString num_conge = ui->sup_2->text();
     conge g;
     g.setnum_conge(num_conge);
     bool test=g.supprimer_conge();
     if(test)
     {   refresh();
         QMessageBox::information(this, "PAS D'ERREUR", "conge supprimé");
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "conge supprimé ");
     }

    ui->sup->clear();
}

void MainWindow::on_comboBox_6_activated(const QString &arg1)
{
   ui->sup_2->setText(arg1);
}





void MainWindow::on_modifier_3_clicked()
{
    tmpconge.setdate_debut(ui->nom_5->text());
    tmpconge.setdate_fin(ui->prenom_5->text());
    tmpconge.settype(ui->matricule_5->text());
    tmpconge.setcin_employer(ui->age_5->text());


    bool test=tmpconge.modifier_conge();

 if(test){ refresh();
         QMessageBox::information(this, "PAS D'ERREUR", " conge modifié");
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", "conge non modifié ");
     }

}



void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    tmpconge.setnum_conge(arg1);
    tmpconge.chercher();
    ui->nom_5->setText(tmpconge.getdate_debut());
    ui->prenom_5->setText(tmpconge.getdate_fin());
    ui->matricule_5->setText(tmpconge.gettype());
    ui->age_5->setText(tmpconge.getcin_employer());

}

void MainWindow::on_lineEdit_20_textChanged(const QString &arg1)
{
    ui->tabconge->setModel(tmpconge.recherche(arg1,etat));
    valeur=arg1;
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
     etat=arg1;
     ui->tabconge->setModel(tmpconge.recherche(valeur,etat));

}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlot->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
         // amande->setName("Repartition des reservation selon les destinations");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;
          tmpconge.statistique(&ticks,&labels);



          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlot->xAxis->setTicker(textTicker);
          ui->customPlot->xAxis->setTickLabelRotation(60);
          ui->customPlot->xAxis->setSubTicks(false);
          ui->customPlot->xAxis->setTickLength(0, 4);
          ui->customPlot->xAxis->setRange(0, 8);
          ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->xAxis->grid()->setVisible(true);
          ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlot->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlot->yAxis->setRange(0,10);
          ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlot->yAxis->setLabel("Statistiques");
          ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->grid()->setSubGridVisible(true);
          ui->customPlot->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot->yAxis->setLabelColor(Qt::white);
          ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select num_conge from conge");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlot->legend->setVisible(true);
          ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlot->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlot->legend->setFont(legendFont);
          ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


          refresh();
}
