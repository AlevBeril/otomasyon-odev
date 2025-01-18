#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>           
using namespace std;


struct Urun {
    int urunKodu;
    string urunAdi;
    string tur;
    double fiyat; 
    int stok;                         
    string renk;                 
};

void UrunEkle();
void UrunArama();
void UrunSil();
void UrunGuncelleme();


int main(){
	
	char anamenu;
	do{
	system("cls");
	
	cout << "|-------Hosgeldiniz------|" << endl ;
	cout << "|      Secim Yapiniz     |" << endl ;
	cout << "|   1- Urun Ekleme       |" << endl ;
	cout << "|     2- Urun Arama      |"<< endl;
	cout << "|    3- Urun Sil         |"<< endl;
	cout << "|    4- Urun Duzenle     |"<< endl;
	cout << "|------------------------|" << endl ;
    char secim;
	cin>> secim;
	
	switch(secim) 
	{
		case '1' : 
		{
		UrunEkle();
		break;	
		}
		case '2' : 
		{
		 UrunArama()	;
		 break;
		}
		case '3' : 
		{
		 UrunSil()	;
		 break;
		}
		case '4' : 
		{
		 UrunGuncelleme()	;
		 break;
		}
		
	}
	
	cout << "Anamenuye Donmek icin: a basin cikmak i�in: c" <<endl ; 
	anamenu=getche();
	
    }while(anamenu=='a');
     

return 0;
}

Urun urun;

void UrunEkle()
{
	ofstream yaz("urun.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	do{
       
        cout << "Urun Kodu giriniz: ";
        cin >> urun.urunKodu;
	   
        cout << "Urun adini giriniz: ";
        cin >> urun.urunAdi;

        cout << "Urun turunu giriniz (Perde, Hali, vb.): ";
        cin >> urun.tur;

        cout << "Urun fiyatini giriniz: ";
        cin >> urun.fiyat;

        cout << "Urun stok giriniz: ";
        cin >> urun.stok; 

        cout << "Urun Renk giriniz: ";
        cin >> urun.renk;

        yaz.write((char*)&urun, sizeof(urun));
        
        adet++;

        cout << "Baska kayit eklemek ister misiniz? (E/H): ";
        cin >> secim;
        cout << endl;
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet Urun Ekledi.." << endl;
	
	yaz.close();
	
}

void UrunArama()
{
	
	ifstream oku("urun.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(urun);
	cout << "Toplam Urun Kayit Sayisi:"<< kayits << endl;

cout <<"Aranan Urun Kodunu Giriniz"<< endl;
int kod;
cin>> kod;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			
			oku.seekg(i*sizeof(urun));
			oku.read((char*)&urun, sizeof(urun));
			
			 if (urun.urunKodu==kod) {
            cout << "Urun Bulundu!" << endl;
            cout << "Urun Adi: " << urun.urunAdi << endl;
            cout << "Fiyat: " << urun.fiyat << endl;
            cout << "Renk: " << urun.renk << endl;
            cout << "Stok: " << urun.stok << endl;
            cout<<"Urun Kodu"<<urun.urunKodu<<endl;
           }
		}
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	oku.close();
}

void UrunSil()
{
	
     char secim= ' ';
     bool var=false;
     
    ifstream oku("urun.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(urun);
	int kod;
     cout<<"Kaydini Sileceginiz KOdu Giriniz : ";
     cin>>kod;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(urun));
			oku.read((char*)&urun, sizeof(urun));
			
          if(urun.urunKodu==kod)
            {
             cout << "Urun Bulundu!" << endl;
            cout << "Urun Adi: " << urun.urunAdi << endl;
            cout << "Urun Turu: " << urun.tur << endl;
            cout << "Fiyat: " << urun.fiyat << endl;
            cout << "Renk: " << urun.renk << endl;
            cout << "Stok: " << urun.stok << endl;
                
         	 				  
                cout<<"\n\nSilmek Istediginiz Kayit Bu Mu? [E/H] : ";
                 secim=getche();

            if(secim == 'H' || secim == 'h')
              {      
			    Urun y_urun;
                ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
                
                 y_urun.urunKodu=urun.urunKodu;
                 y_urun.renk=urun.renk;
                y_urun.stok=urun.stok;     
                y_urun.fiyat=urun.fiyat;
                y_urun.urunAdi=urun.urunAdi;
                y_urun.tur=urun.tur;

                y_dosya.write((char*)&urun, sizeof(urun));
                y_dosya.close();
              }
            if(secim=='e'||secim=='E')
              {
   			   	var=true;
  		 	  }
            }
             else
             {
              Urun y_urun;
              ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
              
               y_urun.urunKodu=urun.urunKodu;
                 y_urun.renk=urun.renk;
                y_urun.stok=urun.stok;     
                y_urun.fiyat=urun.fiyat;
                y_urun.urunAdi=urun.urunAdi;
                y_urun.tur=urun.tur;
                       
              y_dosya.write((char*)&urun, sizeof(urun));
              y_dosya.close();
             }
     }
    oku.close();
    if(var)
    {
               remove("urun.dat");
               rename("Yedek.dat","urun.dat");
               cout<<"\n Kayit Silindi"<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\n Kayit Bulunamadi"<<endl;                  
    }
	
	
}

void UrunGuncelleme()
{
	
     char secim= ' ';
     bool var=false;
     
    ifstream oku("urun.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(urun);
		int kod;
     cout<<"Kaydini DuzelteceginizUrun kodunu Giriniz : ";
     cin>>kod;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(urun));
			oku.read((char*)&urun, sizeof(urun));
			
     	    if(urun.urunKodu==kod)
            {
             cout << "Urun Bulundu!" << endl;
            cout << "Urun Adi: " << urun.urunAdi << endl;
            cout << "Urun Turu: " << urun.tur << endl;
            cout << "Fiyat: " << urun.fiyat << endl;
            cout << "Renk: " << urun.renk << endl;
            cout << "Stok: " << urun.stok << endl;
                 
                  cout<<"\n\nDuzeltmek Istediginiz Kayit Bu Mu? [E/H] : " << endl;
                  secim=getche();

                  if(secim == 'E' || secim == 'e')
                  {
                     	var=true;
                        
                        ofstream dosya("Yedek.dat",ios::app|ios::binary);
        cout << "Urun Kodu giriniz: ";
        cin >> urun.urunKodu;
	   
        cout << "Urun adini giriniz: ";
        cin >> urun.urunAdi;

        cout << "Urun turunu giriniz (Perde, Hali, vb.): ";
        cin >> urun.tur;

        cout << "Urun fiyatini giriniz: ";
        cin >> urun.fiyat;

        cout << "Urun stok giriniz: ";
        cin >> urun.stok; 

        cout << "Urun Renk giriniz: ";
        cin >> urun.renk;
		  
                        dosya.write((char*)&urun, sizeof(urun));
                        dosya.close();
            	  }
            	 else
                 	{
                Urun y_urun;
              ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
              
               y_urun.urunKodu=urun.urunKodu;
                 y_urun.renk=urun.renk;
                y_urun.stok=urun.stok;     
                y_urun.fiyat=urun.fiyat;
                y_urun.urunAdi=urun.urunAdi;
                y_urun.tur=urun.tur;
                       
              y_dosya.write((char*)&urun, sizeof(urun));
              y_dosya.close();
                   }
     }
 }
    oku.close();
    if(var)
    {
               remove("urun.dat");
               rename("Yedek.dat","urun.dat");
               cout<<"\nKayit Duzeltildi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKayit Bulunamadi"<<endl;                  
    }

}


