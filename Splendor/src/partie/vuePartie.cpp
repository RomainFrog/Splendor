#include <QLabel>
//#include <QlineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>
#include "./vuePartie.h"
//#include "vuecarte.h"

VuePartie::VuePartie(QWidget *parent) : QWidget(parent), vuecartes(20,nullptr), vuecartesNobles(5,nullptr)
{
    setWindowTitle("Splendor !"); // modifier le titre de la fenêtre

    banque = new QLabel("Banque:(émeraude/saphir/rubis/diamant/onyx/joker)");

    carteNobles = new QLabel("Carte Nobles : ");

    emeraudeBanque=new QLCDNumber;
    emeraudeBanque->display(QString::number(controleur.getPlateau().getBanque(0)));
    emeraudeBanque->setFixedHeight(30);
    saphirBanque=new QLCDNumber;
    saphirBanque->display(QString::number(controleur.getPlateau().getBanque(1)));
    saphirBanque->setFixedHeight(30);
    rubisBanque=new QLCDNumber;
    rubisBanque->display(QString::number(controleur.getPlateau().getBanque(2)));
    rubisBanque->setFixedHeight(30);
    diamantBanque=new QLCDNumber;
    diamantBanque->display(QString::number(controleur.getPlateau().getBanque(3)));
    diamantBanque->setFixedHeight(30);
    onyxBanque=new QLCDNumber;
    onyxBanque->display(QString::number(controleur.getPlateau().getBanque(4)));
    onyxBanque->setFixedHeight(30);
    jokerBanque=new QLCDNumber;
    jokerBanque->display(QString::number(controleur.getPlateau().getBanque(5)));
    jokerBanque->setFixedHeight(30);

    layoutInformations=new QHBoxLayout;
    layoutCartes = new QGridLayout;
    layoutCartesNobles = new QGridLayout;
    couche = new QVBoxLayout;

    //Informations
    layoutInformations->addWidget(banque);
    layoutInformations->addWidget(emeraudeBanque);

    layoutInformations->addWidget(saphirBanque);
    layoutInformations->addWidget(rubisBanque);
    layoutInformations->addWidget(diamantBanque);
    layoutInformations->addWidget(onyxBanque);
    layoutInformations->addWidget(jokerBanque);


//    // Create the button, make "this" the parent
//    m_button = new QPushButton("My Button", this);
//      // set size and location of the button
//   m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    //création des vues des cartesDeveloppement
    for(size_t i=0; i<12;i++)
        vuecartes[i] = new VueCarte;
    for(size_t i=0; i<12;i++){
        layoutCartes->addWidget(vuecartes[i],i/4,i%4);//ajout de la carte sur la grille
        connect(vuecartes[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
    }

    size_t nb_joueur = controleur.getNbJoueurs();

    //création des vues des cartesNobles
    for(size_t i=0; i<nb_joueur + 1;i++)
        vuecartesNobles[i] = new VueCarte;
    for(size_t i=0; i<nb_joueur + 1;i++){
        layoutCartesNobles->addWidget(vuecartesNobles[i],i/(nb_joueur+1),i%(nb_joueur+1));//ajout de la carte sur la grille
        connect(vuecartesNobles[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
    }

    //affectation des cartes du plateau aux vues des cartes
    size_t i = 0;

    //Carte de développement
    for(int j = 0; j<3; j++){
        for(auto it: controleur.getPlateau().getNiveauDeveloppement(j).getCartes()){
            //it->afficherCarte();
            vuecartes[i]->setCarte(*it);
            i++;
        }
    }

    //Carte Nobles
    size_t j = 0;
    for(auto it: controleur.getPlateau().getNiveauNobles().getCartes()){
        vuecartesNobles[j]->setCarte(*it);
        j++;
    }

    playersData = new QLabel("Player Data : ");
    QString str;
    for (int i = 0; i < controleur.getNbJoueurs(); ++i){
        if (i > 0) {
            str += "\n";
        }
        str += "id :" + QString::number(controleur.getJoueur(i).getId()) + "   ";
        str += QString::fromStdString(controleur.getJoueur(i).getNom()) + "   ";
        str += "PDV:" + QString::number(controleur.getJoueur(i).getPDV()) + "   ";

        str += "Inventaire: [";
        for (size_t j = 0; j < 5; j++) {
            str += QString::number(controleur.getJoueur(i).getInventaire()[j]) + ",";
        }
        str += QString::number(controleur.getJoueur(i).getInventaire()[5]) + "]   ";

        str += "Bonus: [";
        for (size_t j = 0; j < 4; j++) {
            str += QString::number(controleur.getJoueur(i).getBonus()[j]) + ",";
        }
        str += QString::number(controleur.getJoueur(i).getInventaire()[4]) + "]   ";


        //Manque affichage des cartes Reserve et CarteRemportées ? (pas besoin carteRemporté?)
        //controleur.getJoueur(i).getReserve();
        //controleur.getJoueur(i).getCartesRemportees();
    }
    playersData->setText(str);

    couche->addLayout(layoutInformations);
    couche->addLayout(layoutCartes);

    //affiche juste CarteNobles :
    couche->addWidget(carteNobles);

    couche->addLayout(layoutCartesNobles);
    couche->addWidget(playersData);
    setLayout(couche);
}

void VuePartie::carteClique(VueCarte* vc){
   return;
}

//void VuePartie::carteClique(VueCarte* vc){
//    if(!vc->cartePresente()){
//        //qDebug("ajouter carte !\n");
//        if(controleur.getPioche().estVide()/*.getNbCartes() == 0*/){
//            QMessageBox message(QMessageBox::Icon::Warning, "Attention", "La pioche est vide");
//            message.exec();
//        }
//        controleur.distribuer(); //ajout d'une carte
//        //mise à jour des affectations des cartes aux vues des cartes
//        size_t i = 0;
//        for(auto it=controleur.getPlateau().begin();it!=controleur.getPlateau().end();++it){
//            vuecartes[i]->setCarte(*it);
//            i++;
//        }
//        nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
//    } else {
//        if(vc->isChecked()){ //une nouvelle carte a été selectionnée
//            selectionCartes.insert(&vc->getCarte()); //on insere la carte dans l'ensemble des cartes sélectionnées

//            if(selectionCartes.size() == 3){ //on a une combinaison qui peut être un SET
//                //on crée et teste une combinaison
//                vector<const Set::Carte*> c(selectionCartes.begin() , selectionCartes.end());
//                Set::Combinaison comb(*c[0], *c[1], *c[2]);

//                if(comb.estUnSET()){ //c'est un SET ! Il faut mettre à jour le plateau
//                    //Retirer les cartes du plateau
//                    controleur.getPlateau().retirer(*c[0]);
//                    controleur.getPlateau().retirer(*c[1]);
//                    controleur.getPlateau()..retirer(*c[2]);
//                    selectionCartes.clear(); //il n'y a plus de cartes sélectionnées

//                    //s'il n'y a pas au moins 12 cartes sur le plateau, on le complète
//                    if(controleur.getPlateau().getNbCartes() < 12){
//                        controleur.distribuer();
//                    }
//                    //mise à jour du score
//                    scoreValue++;
//                    scoreJoueur->display(scoreValue);
//                    //mise à jour de la vue du plateau
//                    //-> nettoyage du plateau et mise à jour de la vue des cartes
//                    for (size_t i=0; i<vuecartes.size(); i++) {
//                        vuecartes[i]->setNoCarte();
//                    }

//                    size_t i = 0;
//                    for(auto it=controleur.getPlateau().begin();it!=controleur.getPlateau().end();++it){
//                        vuecartes[i]->setCarte(*it);
//                        i++;
//                    }

//                    //mise à jour de la vue de la pioche
//                    nbCartesPioche->setValue(controleur.getPioche().getNbCartes());

//                } else {
//                    QMessageBox message(QMessageBox::Icon::Warning, "Attention", "Ce n'est pas un set");
//                    message.exec();
//                    //déselection des cartes
//                    for (size_t i=0; i<vuecartes.size(); i++) {
//                        vuecartes[i]->setChecked(false);
//                    }
//                    selectionCartes.clear(); //l'ensemble des cartes sélectionnées est vide
//                }
//            }

//        } else {
//            //la carte est désélectionnéee
//            selectionCartes.erase(&vc->getCarte());
//        }
//    }

//    update(); //mise à jour de la vue
//}


//#################################################################
//#################################################################
// //TODO: TO DELETE :
//#################################################################
//#################################################################



#include <QPainter>
#include <QString>
#include <QStaticText>

VueCarte::VueCarte(const Splendor::Carte& c, QWidget *parent) : QPushButton(parent),carte(&c)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(60,100);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(60,100);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void VueCarte::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);

    // rectangle autour de la carte
    pen.setColor(QColor("gray"));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawRect(QRect(2, 2, width() - 2, height() - 2));

    if (carte==nullptr) { // si la vue de carte n'a pas de carte on affiche un message
        painter.drawText(QRect(7,25,50,30), Qt::AlignCenter, tr("vide"));
        //pen.setColor(QColor("dark green")); brush.setColor(QColor("dark green")); break;
        //Set::Remplissage::vide: brush.setStyle(Qt::NoBrush);
        return;
    }

    painter.drawText(QRect(7,25,50,30), Qt::AlignCenter, tr("ceci \n carte"));

    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing, true);


    if (isChecked()) { // si la carte est sélectionnée, on ajoute une croix noire
        pen.setColor(QColor("black"));
        painter.setPen(pen);
        painter.drawLine(QPoint(0,0), QPoint(width(),height()));
        painter.drawLine(QPoint(width(),0), QPoint(0,height()));
    }

}

