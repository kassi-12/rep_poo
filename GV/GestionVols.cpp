#include<iostream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>  

using namespace std;
//debut de claas passager
class Passager {
    private:
    int id;
    string nom,prenom,adress;
    int age,tele;
    public:
    int getId(){
        return id;
    }
    int getAge(){
        return age;
    }
    void saisir(){
     
        cout<<"--->Entrer l'id de passager \n";
        cin>>id;
        cout<<"--->Entrer le nom de passager \n";
        cin>>nom;
        cout<<"--->Entrer le prenom de passager \n";
        cin>>prenom;
        cout<<"--->Entrer l'adress de passager \n";
        cin>>adress;
        cout<<"--->Entrer l'age de passager \n";
        cin>>age;
        cout<<"--->Entrer le numero de telephon de passager \n";
        cin>>tele;
    }
    void afficherP(){
                cout<<"\n==============Affichage de Passager=======================\n";
        cout<<"\t id : "<<id<<"\n\t nom : "<<nom<<"\n\t prenom : "<<prenom<<"\n\t adress : "<<adress<<"\n\t age : "<<age<<"\n\t numero de tele : "<<tele<<"\n\t  ";                                                                                             
    }
     void ajoute(){
     
        // cout<<"--->Entrer l'id de passager \n";
        // cin>>id;

        cout<<"--->Entrer le nom de passager \n";
        cin>>nom;
        cout<<"--->Entrer le prenom de passager \n";
        cin>>prenom;
        cout<<"--->Entrer l'adress de passager \n";
        cin>>adress;
        cout<<"--->Entrer l'age de passager \n";
        cin>>age;
        cout<<"--->Entrer le numero de telephon de passager \n";
        cin>>tele;
    }

    void modifierInformation( string newNom,  string newPrenom, string newAdress, int newAge, int newTele) {
        cout << "Modifier les informations du passager:\n";
        cout << "\n=====================================\n";

        nom = newNom;
        prenom = newPrenom;
        adress = newAdress;
        age = newAge;
        tele = newTele;
    }

};
    

//fin de class passager
//---------------------------------------------------------------------
//debut de class avion
class Avion {

    private:
    string code;
    string pilot;
    int modele,capacite,nbVolsAssure ;
    tm dateFabrication={};
    
    public:

//year
    int getCurrentYear() {
    time_t t = time(0);
    tm* now = localtime(&t);

    int currentyear = now->tm_year + 1900;
    return currentyear;
}
//month
    int getCurrentmonth() {
    time_t t = time(0);
    tm* now = localtime(&t);
    
    int currentmonth=now->tm_mon+1;
    return currentmonth;
}
//day
    int getCurrentday() {
    time_t t = time(0);
    tm* now = localtime(&t);
    
    int currentday=now->tm_mday;
    return currentday;
}

        void saisir()
    {
        cout<<"\n===========Saisir Avion==========================\n";

        cout<<"--->Entrer le code d'avion :\n";
        cin>>code;
        cout<<"--->Entrer le pilot d'avion :\n";
        cin>>pilot;
        cout<<"--->Entrer le modele d'avion : \n";
        cin>>modele;
        cout<<"--->Entrer la capacite d'avion :\n";
        cin>>capacite;
   
        int i;

        // Control de saisie de date
    do {
    cout << "--->Entrer la date de fabrication avion (DD MM YYYY):  \n ";
    int dd, mm, yy;
    cin >> dd >> mm >> yy;

    // Date validation
    if ((dd >= 1 && dd <= 31) && (mm >= 1 && mm <= 12) && (yy >= 1900 && yy <= getCurrentYear())) {
        dateFabrication.tm_mday = dd;
        dateFabrication.tm_mon = mm;
        dateFabrication.tm_year = yy;
        i = 1;
    } else {
        cout << "\t\t incorrect  date. S'il veut  entrer  correct date.\n";
        i = 2;
    }
} while (i == 2);
   

        cout<<"--->Entrer le nombre de vols assures d'avion : \n";
        cin>>nbVolsAssure;
     }
    void afficher(){
                cout<<"\n===========Afficher Avion==========================\n";

        cout<<"\n \t code avion : "<<code<<"\n \t pilot : "<<pilot<<"\n \t modele : "<<modele<<"\n \t capacite : "<<capacite<<"\n \t date de fabrication : "<<dateFabrication.tm_mday<<"/"<<dateFabrication.tm_mon<<"/"<<dateFabrication.tm_year<<"\n \t nombre de vols assures : "<<nbVolsAssure<<"\n } ";                                                                                             
                   }

};
//fin de class avion
//----------------------------------------------------------------------------------------------
//debut de class vol
class Vol {
    private:
    int idVol;
    Avion avion; 
    vector<Passager> passagers;  
    public:
    tm dateDipart={},dateArrivee={};
    

//getters-setters----------------------------------------------------------------------------------------//
    int getIdVol(){return idVol;}
    struct tm& getDateDipart() {
        return dateDipart;
    }
  vector<Passager>& setPassagers(const Passager p) {
    passagers.push_back(p);
    return passagers;
}
    vector<Passager>& getPassagers() {
        return passagers;
    }
    void setAvion(const Avion& a) {
        avion = a;
    }
//get the current date ---------------------------------------------------------------------------//
//year
    int getCurrentYear() {
    time_t t = time(0);
    tm* now = localtime(&t);

    int currentyear = now->tm_year + 1900;
    return currentyear;
}
//month
    int getCurrentmonth() {
    time_t t = time(0);
    tm* now = localtime(&t);
    
    int currentmonth=now->tm_mon+1;
    return currentmonth;
}
//day
    int getCurrentday() {
    time_t t = time(0);
    tm* now = localtime(&t);
    
    int currentday=now->tm_mday;
    return currentday;
}
//------------------------saisir de vol-----------------------------------------------------------//
    void saisir(){
        // avion.saisir();
        // Passager passager;
        //    cout<<"\n===========------------Saisir Passager ----==========================\n";
        // passager.saisir();
        // passagers.push_back(passager);
        cout <<"\n=====================Saisir Vol========================================\n";
                 cout << "--->Entrer l'id de vol \n ";
                 cin >> idVol;
            int i=1;
    do {
         cout << "--->Entrer la date de depart (DD MM YYYY):  \n ";
            int dd, mm, yy;
         cin >> dd >> mm >> yy;
        // Date validation
         if ((dd >= 1 && dd <= 31)&&(getCurrentday()) && (mm >= 1 && mm <= 12)&&(getCurrentmonth()>=mm) && (getCurrentYear()) >= yy && yy < 10000) {
        dateDipart.tm_mday = dd;
        dateDipart.tm_mon = mm;
        dateDipart.tm_year = yy;
        i = 1;
    } else {
        cout << "\t\t incorrect  date. S'il veut  entrer  la date correct.\n";
        i = 2;
    }
    } while (i == 2);   
//////////////////////////////////////////
    int t = 1;
do {
    cout << "--->Enter the arrival date (DD MM YYYY):  \n ";
    int da, ma, ya;
    cin >> da >> ma >> ya;

    // Date validation
    if ((da >= 1 && da <= 31) && (ma >= 1 && ma <= 12) && (ya >= 1900 && ya < 10000) &&
        // Check if arrival date is after departure date
        ((ya > dateDipart.tm_year) || (ya == dateDipart.tm_year && ma > dateDipart.tm_mon) ||
         (ya == dateDipart.tm_year && ma == dateDipart.tm_mon && da > dateDipart.tm_mday))) {
        dateArrivee.tm_mday = da;
        dateArrivee.tm_mon = ma;
        dateArrivee.tm_year = ya;
        t = 1;
    } else {
        cout << "\t\t Incorrect date. Please enter a correct date after the departure date.\n";
        t = 2;
    }
} while (t == 2); 
    }
    
    //-----------------------------------------------------------affichage-------------------------------------------//
    void afficher(){
        cout<<"\n============ Afficher Vol =========================\n";
        cout<<"\n\t id vol : "<<idVol;
        
        for(auto& p : passagers) {
            p.afficherP();  
        }
        avion.afficher();            
        
         cout<<" \n\t date de depart : "<<dateDipart.tm_mday<<"/"<<dateDipart.tm_mon<<"/"<<dateDipart.tm_year<<" \n\t date d'arrivee :"<<dateArrivee.tm_mday<<"/"<<dateArrivee.tm_mon<<"/"<<dateArrivee.tm_year;

                 cout<<"\n===========Fin affichage de vol==========================\n";

                  }
//----------------------------------Les test de passager -------------------------------//
         
        bool passagerAppartientInVol(Passager &passenger){
        for(auto &p : passagers) {
        if (p.getId() == passenger.getId()) {
            return true;
                }
         }
            return false;
        }
        bool passagerAppartientInVol(int id){
        for(auto &p : passagers) {
        if (p.getId() == id) {
            return true;
            }
        }
            return false;
        }
//----------------------------------Ajouter de passager -------------------------------//

    void ajouterPassager(Passager &passager ) {
        passagers.push_back(passager);
    }
  
//----------------------------------Modification de passager -------------------------------//
   void modifierInformationPassager(int id,  string newNom,  string newPrenom,  string newAdress, int newAge, int newTele) {
        for (auto &p : passagers) {
            if (p.getId() == id) {
                p.modifierInformation(newNom, newPrenom, newAdress, newAge, newTele);
                cout << "Les informations du passager ont ete modifiees.\n";
                return;
            }
        }
        cout << "Le passager n'existe pas dans le vol.\n";

    }
//------------------------------- Modification de date vol --------------------------------------// 
    void modifierDate( int newdd ,int newda ,int newmd ,int newma,int newyd ,int newya) {
         cout << "\n=====================================\n";
        cout << "\n---------------------Modifier les dates ----------------------\n";

        dateDipart.tm_mday = newdd;
        dateDipart.tm_mon = newmd;
        dateDipart.tm_year = newyd; 
        dateArrivee.tm_mday = newda;
        dateArrivee.tm_mon = newma;
        dateArrivee.tm_year =newya;
        cout<<"la date a ete bien modifier"; 
    }
    //------------------- vol test exictence -----------------------------------//


    //-------------------- test Passager dans tableau---------//
    bool passagerAppartientAuVector(Passager& passagerATester) {
        for (Passager& passager : passagers) {
            if (passager.getId() == passagerATester.getId()) {
                return true;
            }
        }
        return false;
    }
    bool ajouterPassagerInVol( Passager& passager, Vol& vol) {
    // test si le passager existe deja 
    if (vol.passagerAppartientInVol(passager.getId())) {
        cout << "Le passager existe déjà dans le vol." << endl;
        return false;
    } else {
        // ajouter passager a vol
        vol.ajouterPassager(passager);
        cout << "Le passager a été ajouté au vol." << endl;
        return true;
    }
}

    };


    bool volAppartientAuTableau( int id, vector<Vol>& tableauDeVols) {
    for (auto& v : tableauDeVols) {

        if (v.getIdVol()==id) {
            return true;
        }
    }
    return false;
    }
// ajouter vol  est tester son existence
   bool ajouterVolAuTableau(Vol& volAjouter, vector<Vol>& tableauDeVols) {
    for (Vol& existingVol : tableauDeVols) {
        if (existingVol.getIdVol() == volAjouter.getIdVol()) {
            // vol existe dans le tableau de vols
            return false;
        }
    }

    // sinon ajouter dans le tableau
    tableauDeVols.push_back(volAjouter);
    return true;
}
//----------------------------------Affichage des informations de tous les vols-----------------------//
    void afficherInformationsTableauVols( vector<Vol>& tableauDeVols) {
    cout << "\n================ Affichage des informations de tous les vols ======================\n";

    // Iterate through the array of flights
    for ( Vol& vol : tableauDeVols) {
        vol.afficher();  // Assuming you have an afficher function in the Vol class
        cout << "\n-----------------------------\n";
    }

    cout << "\n======================================================================\n";
}
//---------------------------------Affichage des vols du passager-----------------------------------------//
    void afficherVolsPassager( Passager& passager,  vector<Vol>& tableauDeVols) {
    cout << "\n============= Affichage des vols du passager ================\n";

    for ( Vol& vol : tableauDeVols) {
        if (vol.passagerAppartientInVol(passager.getId())) {
            vol.afficher();
            cout << "\n-----------------------------\n";
        }
    }

    cout << "\n===============================================================\n";
}
//---------------- Affichage des passagers ayant moins de 10 ans-------------------//
    void afficherPassagersMoinsDe10Ans( vector<Passager>& passagers) {
    cout << "\n============== Affichage des passagers ayant moins de 10 ans ==============\n";

    for ( Passager& passager : passagers) {
        if (passager.getAge() < 10) {
            passager.afficherP();
            cout << "\n-----------------------------\n";
        }
    }

    cout << "\n==========================================================================\n";
}
//-----------------------Affichage les vol de londemin--------------------//

    void displayFlightsTomorrow(vector<Vol>& tableauDeVols) {
    time_t currentTime = time(nullptr);
    struct tm* localTime = localtime(&currentTime);

    localTime->tm_mday++;
    cout << "\n===================================Affichage les vol de londemin=======================================\n";
    cout << "les vol de londemin:\n";

    for (Vol& vol : tableauDeVols) {
        
        if (vol.getDateDipart().tm_year == localTime->tm_year &&
            vol.getDateDipart().tm_mon == localTime->tm_mon &&
            vol.getDateDipart().tm_mday == localTime->tm_mday) {
    

            cout << "---------vol details:----------------\n";
            vol.afficher();
        }
    }
    }
    // sup vol---------------------------------------------------------------//
    bool supprimerVoldansTableau(int VolId, vector<Vol>& tableauDeVols) {
    for (auto it = tableauDeVols.begin(); it != tableauDeVols.end(); ++it) {
        if (it->getIdVol() == VolId) {
            tableauDeVols.erase(it);
            cout << "vol supprimer\n";
            return true;
        }
    }

     
    cout << "vol non trouve \n";
    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    int menu;
   
    do {
         cout<<"==================== MENU =======================";
         cout<<"+-----------------------------------------------+";
         cout<<"\nChoisissez le numero de l'operation choisie : \n";
         cout<<"1-Saisir un passager \n";
         cout<<"2-Saisir un avion \n";
         cout<<"3-Saisir un vol \n";
         cout<<"4-afficher le passager \n";
         cout<<"5-afficher l'avion \n";
         cout<<"6-afficher le vol  \n";
         cout<<"0-Quitte   \n";

         cin>>menu;
    
    Passager passager;
    Avion avion;
    Vol vol;
        switch(menu){
            case 1:
            passager.saisir();
            vol.setPassagers(passager);
                break;
            case 2:
            avion.saisir();
            vol.setAvion(avion);
                break;
            case 3:
            vol.saisir();
                break;
            case 4:
            passager.afficherP();
                break;
             case 5:
            avion.afficher();
                break;
             case 6:
            vol.afficher();
                break;
            case 0 :
                break;
            default :
            cout <<"votre choix n'existe pas . choisir un nombre existe dans le menu \n";
        }

    }while(menu!=0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// int main() {
//     Vol vol;
//     vol.saisir();
// //--------------------Tester le exictence de passager----------------------------------//    
//     int id_toCheck;
//     cout<<"\n============= tester le exictence de passager =========================\n";

//     cout<<"===== entry l'id de passager pour tester son exictence\n";
//     cin>>id_toCheck;

//     if (vol.passagerAppartientInVol(id_toCheck)) {
//         cout << "\n\tLe passager appartient au vol." << endl;
//     } else {
//         cout << "\n\tLe passager n'appartient pas au vol." << endl;
//     }
    
// //------------------------------Ajouter Passager------------------------------------------//
// int idP,deja=2;
// cout << "\n================== Ajouter un Passager =========================\n";
//     Passager newPassager;
//    do {
//      cout<<"------>entrer l'id de passager : \n";
//      cin >> idP;
//     if (!(vol.passagerAppartientInVol(idP))) {
//         deja=2;
           
//             newPassager.ajoute();
//             vol.ajouterPassager(newPassager);
//             cout << "\nLe passager a ete ajoute au vol." << endl;
            
//     } else {
//         deja=1;
//         cout << "\nLe passager existe deja dans le vol." << endl;
//         cout << "\n================== Ajouter un nouveau =========================\n";

//     }
//    } while(deja==1);
   
// //----------------------------------Modification de passager -------------------------------//
//     cout << "\n=============== Modification de passager ===========================\n";
//      int id,tt=1;
//      do {
//            cout << "---->entry id de passager a modifier : ";
//             cin >> id;

//     string newNom, newPrenom, newAdress;
//     int newAge, newTele;
//      if (vol.passagerAppartientInVol(id)) {
//         tt=1;
//             cout << "Entrer un nouveau nom de passager : ";
//             cin >> newNom;
//             cout << "Entrer un nouveau prenom de passager : ";
//             cin >> newPrenom;
//             cout << "Entrer nouvelle adresse de passager : ";
//             cin >> newAdress;
//             cout << "Entrer nouvel age du passager : ";
//             cin >> newAge;
//             cout << "Entrer nouveau numero de telephone de passager : ";
//             cin >> newTele;

//             vol.modifierInformationPassager(id, newNom, newPrenom, newAdress, newAge, newTele);
        
//     } else {
//         cout << "\nLe passager n'existe pas dans le vol." << endl;
//         tt=2;
//     }
//      } while(tt==2);
     
// //------------------------------- Modification de date vol --------------------------------------// 
// int newdd, newda, newmd, newma, newyd, newya;

//     cout << "\n----------------Enter a new departure date --------------------\n ";

//     cout << "\n\t--->Entrer la date de depart (DD MM YYYY):  \n ";
//     cin >> newdd >> newmd >> newyd;


// // Comparaison des Dates
// if (newyd > vol.dateDipart.tm_year || newyd < vol.dateDipart.tm_year) {
//     if (newyd > vol.dateDipart.tm_year) {
//         cout << "The new date is after the current date.\n";
//     } else {
//         cout << "The current date is after the new date.\n";
//     }
// } else if (newmd > vol.dateDipart.tm_mon || newmd < vol.dateDipart.tm_mon) {
//     if (newmd > vol.dateDipart.tm_mon) {
//         cout << "The new date is after the current date.\n";
//     } else {
//         cout << "The current date is after the new date.\n";
//     }
// } else if (newdd > vol.dateDipart.tm_mday || newdd < vol.dateDipart.tm_mday) {
//     if (newdd > vol.dateDipart.tm_mday) {
//         cout << "The new date is after the current date.\n";
//     } else {
//         cout << "The current date is after the new date.\n";
//     }
// } else {
//     cout << "The dates are equivalent.\n";
// }

//         cout << "\n\t--->Entrer la date d'arrivee (DD MM YYYY):\n ";
//         cin >> newda >>newma >> newya;

// // Comparaison des Dates
// if (newya > vol.dateArrivee.tm_year || newya < vol.dateArrivee.tm_year) {
//     if (newya > vol.dateArrivee.tm_year) {
//         cout << "La nouvelle date est postérieure à la date actuelle.\n";
//     } else {
//         cout << "The current date is after the new date.\n";
//     }
// } else if (newma > vol.dateArrivee.tm_mon || newma < vol.dateArrivee.tm_mon) {
//     if (newma > vol.dateArrivee.tm_mon) {
//         cout << "The new date is after the current date.\n";
//     } else {
//         cout << "The current date is after the new date.\n";
//     }
// } else if (newda > vol.dateArrivee.tm_mday || newda < vol.dateArrivee.tm_mday) {
//     if (newda > vol.dateArrivee.tm_mday) {
//         cout << "The new date is after the current date.\n";
//     } else {
//         cout << "The current date is after the new date.\n";
//     }
// } else {
//     cout << "The dates are equivalent.\n";
// }

// vol.modifierDate(newdd, newda, newmd, newma, newyd, newya);

//             //------------------------------ fin Comparaison Date--------------//

//     cout<<"=============================================================================\n";
//         //---------tab de vole tester existence-------------//


//         vector<Vol> tableauDeVols;
//         int idv;

    
//     cout<<"============================ test exictence d'un vol =================================================\n";
//     cout<<"entrer l'id de vol pour tester son exictence \n";
//      cin>> idv;
//         if (volAppartientAuTableau(idv, tableauDeVols)) {

//             cout << "------->Le vol appartient au tableau.\n" << endl;

//         } else {

//             cout << "-------->Le vol n'appartient pas au tableau." << endl;
//         }
//         //----------------------------- Tester si un passager appartient à un tableau donné ------------------//;
//         cout<<"\n================= Tester si un passager appartient à un tableau donné ============================\n\n\n";

//            Passager passagerATester;
//            passagerATester.saisir();
//            vector<Passager> tableauDePassagers;

//          if (vol.passagerAppartientAuVector(passagerATester)) {

//             cout << "\t----->Le passager appartient au vecteur de passagers dans le vol." << endl;

//          } else {

//             cout << "\t----->Le passager n'appartient pas au vecteur de passagers dans le vol." << endl;
//          }
        
//         Vol newVol;      
//         newVol.saisir();
//         cout<<"\n================= Tester si le vol ajouter dans le tableau de vol ou pas ============================\n\n\n";

//         // Tester si le vol ajouter dans le tableau de vol ou pas
//         if (ajouterVolAuTableau(newVol, tableauDeVols)) {

//         cout << "\t----->Le vol a été ajouté au tableau." << endl;

//         } else {

//         cout << "\t----->Le vol existe déjà dans le tableau." << endl;
//         }
//         // -------------------------------------ajouter passager a vol-------------------//
//         cout<<"\n================= ajouter passager a vol ============================\n\n\n";
//         Passager newPassager2;
//         newPassager.saisir(); 

//         Vol nvol;
//         nvol.saisir(); 

//         nvol.ajouterPassagerInVol(newPassager2, nvol);

//         //----------------------------affichage tableau vol--------------//
//             afficherInformationsTableauVols(tableauDeVols);

//         //---------------------------affichage des vol d'un passager------------------------//
//         Passager passagerAffVol;
//         afficherVolsPassager(passagerAffVol, tableauDeVols);
//         //-------------- afficher Passagers Moins De 10 Ans---------------//
//         afficherPassagersMoinsDe10Ans(tableauDePassagers);

//         //----------------supr un vol-------------------------------------//
//         int VolIdSup;
//         cout<<"\n\t----entrer l'id de vol que tu veut supprimer \n";
//         supprimerVoldansTableau(VolIdSup, tableauDeVols);

//         cout<<"\n=================Affichage apre tout operation============================\n\n\n";
//         vol.afficher();
//         getch();
//     return 0;
//     }

