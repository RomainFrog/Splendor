#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <vector>
#include <set>
#include "../controleur/controleur.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;
class VueJoueur;

class VuePartie : public QWidget {
    Q_OBJECT
public:
    explicit VuePartie(QWidget *parent = nullptr);
private:
    Splendor::Controleur controleur; // controleur de la partie //TODO: fixé à 4 joueurs

    // - - - - Jeton - - - -
    QGroupBox *emeraudeBox();
    QLCDNumber* emeraudeBanque;
    QPushButton *emeraudeBouton;

    QGroupBox *saphirBox();
    QLCDNumber* saphirBanque;
    QPushButton *saphirBouton;

    QGroupBox *rubisBox();
    QLCDNumber* rubisBanque;
    QPushButton *rubisBouton;

    QGroupBox *diamantBox();
    QLCDNumber* diamantBanque;
    QPushButton *diamantBouton;

    QGroupBox *onyxBox();
    QLCDNumber* onyxBanque;
    QPushButton *onyxBouton;

    QGroupBox *jokerBox();
    QLCDNumber* jokerBanque;
     // - - - - end Jeton - - - -

    QLabel* banque; // texte
    QLabel* carteNobles; // texte
    QLabel* playersData; // texte

    QHBoxLayout* layoutInformations;
    QGridLayout* layoutCartes; // grille des cartes
    QGridLayout* layoutCartesNobles;
    QVBoxLayout* couche;

    QPushButton *pioche1Bouton;
    QPushButton *pioche2Bouton;
    QPushButton *pioche3Bouton;

    vector<VueCarte*> vuecartes; // adresses des objets VueCarte
    vector<VueCarte*> vuecartesNobles; // adresses des objets VueCarteNobles

    std::set<const Splendor::Carte*> selectionCartes; // ensemble des cartes sélectionnées


    private slots:
        // slots qui gère les clics sur les cartes et boutons
        void carteClique(VueCarte* vc);
        void emeraudeBoutonClique();
        void saphirBoutonClique();
        void rubisBoutonClique();
        void diamantBoutonClique();
        void onyxBoutonClique();
        void pioche1BoutonClique();
        void pioche2BoutonClique();
        void pioche3BoutonClique();

};




//#################################################################
//#################################################################
// //TODO: TO DELETE :
//#################################################################
//#################################################################

#include <QPen>
#include <QBrush>
#include <QPushButton>

class VueCarte : public QPushButton
{
    Q_OBJECT
public:
    VueCarte(const Splendor::Carte& c, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void setCarte(const Splendor::Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    const Splendor::Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    const Splendor::Carte* carte=nullptr;
    QPen pen;
    QBrush brush;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};


class VueJoueur : public QWidget
{
    Q_OBJECT
public:
//    VueJoueur(const Splendor::Joueur& j, QWidget *parent = nullptr);
//    explicit VueJoueur(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    // void setCarte(const Splendor::Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    // void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    //const Splendor::Carte& getCarte() const { return *carte; }
    // bool cartePresente() const { return carte!=nullptr; }

protected:
    //void paintEvent(QPaintEvent *event) override;
private:
//    const Splendor::Joueur* joueur=nullptr;

signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    //void carteClicked(VueCarte*);
public slots:
private slots:
   // void clickedEvent() { emit carteClicked(this); }
};

#endif // VUEPARTIE_H
