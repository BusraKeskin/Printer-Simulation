#include<iostream>
#include<fstream>
#include<math.h>
#define N 10

using namespace std;

struct Kisi{

	string ad;
	string soyad;
	string kullanici_adi;
	string e_posta;
	int dogum_yili;
};
struct Tarih{
	
	int yil;
	int kacinci_gun;
	int kacinci_ay;
	int saat;
	int dakika;
	int saniye;
};
struct Belge{
	string b_yolu;
	string boyut;
	int sayfa_sayisi;
	Kisi kisi;
	Tarih tarih;
};

Belge s1[N];
Belge kuyruk[N];
Belge temp;

void kuyruga_yazma(int i,  ifstream &dosya){
	dosya>>s1[i].b_yolu;
	kuyruk[i].b_yolu = s1[i].b_yolu;
	
	dosya>>s1[i].boyut;
	kuyruk[i].boyut = s1[i].boyut;
	
	dosya>>s1[i].sayfa_sayisi;
	kuyruk[i].sayfa_sayisi = s1[i].sayfa_sayisi;
	
	dosya>>s1[i].kisi.ad;
	kuyruk[i].kisi.ad = s1[i].kisi.ad;
	
	dosya>>s1[i].kisi.soyad;
	kuyruk[i].kisi.soyad = s1[i].kisi.soyad;
	
	dosya>>s1[i].kisi.kullanici_adi;
	kuyruk[i].kisi.kullanici_adi = s1[i].kisi.kullanici_adi;
	
	dosya>>s1[i].kisi.e_posta;
	kuyruk[i].kisi.e_posta = s1[i].kisi.e_posta;
	
	dosya>>s1[i].kisi.dogum_yili;
	kuyruk[i].kisi.dogum_yili = s1[i].kisi.dogum_yili;
	
	dosya>>s1[i].tarih.yil;
	kuyruk[i].tarih.yil = s1[i].tarih.yil;
	
	dosya>>s1[i].tarih.kacinci_gun;
	kuyruk[i].tarih.kacinci_gun = s1[i].tarih.kacinci_gun;
	
	dosya>>s1[i].tarih.kacinci_ay;
	kuyruk[i].tarih.kacinci_ay= s1[i].tarih.kacinci_ay;
	
	dosya>>s1[i].tarih.saat;
	kuyruk[i].tarih.saat= s1[i].tarih.saat;
	
	dosya>>s1[i].tarih.dakika;
	kuyruk[i].tarih.dakika= s1[i].tarih.dakika;
	
	dosya>>s1[i].tarih.saniye;
	kuyruk[i].tarih.saniye= s1[i].tarih.saniye;
}
void slide(int i){
	int j;
	for( j=0;j<i;j++){
	
	kuyruk[j].b_yolu = kuyruk[j+1].b_yolu;
	kuyruk[j].boyut = kuyruk[j+1].boyut;
	kuyruk[j].sayfa_sayisi = kuyruk[j+1].sayfa_sayisi;
	kuyruk[j].kisi.ad = kuyruk[j+1].kisi.ad;
	kuyruk[j].kisi.soyad = kuyruk[j+1].kisi.soyad;
	kuyruk[j].kisi.kullanici_adi = kuyruk[j+1].kisi.kullanici_adi;
	kuyruk[j].kisi.e_posta = kuyruk[j+1].kisi.e_posta;
	kuyruk[j].kisi.dogum_yili = kuyruk[j+1].kisi.dogum_yili;
	kuyruk[j].tarih.yil = kuyruk[j+1].tarih.yil;
	kuyruk[j].tarih.kacinci_gun = kuyruk[j+1].tarih.kacinci_gun;
	kuyruk[j].tarih.kacinci_ay = kuyruk[j+1].tarih.kacinci_ay;
	kuyruk[j].tarih.saat = kuyruk[j+1].tarih.saat;
	kuyruk[j].tarih.dakika = kuyruk[j+1].tarih.dakika;
	kuyruk[j].tarih.saniye = kuyruk[j+1].tarih.saniye;

	}
	
} 

bool kuyrukta_yer_var_mi(){
	
	
	int a=0;
	while(a<N && kuyruk[a].b_yolu.length()!=0){//icinde bir sey varsa a'yi arttir N olana kadar
		a++;
	}
	if (a==N)// a N oldu demek ki hep doluydu
		return 0;
	else // a N'den kucuktur demek ki bir yerde bos var
		return 1;
}

int main () 
{
	bool yazici_musait=1;
	int dosya_sayisi=0;
	int yazilmis_dosya_sayisi=0;
	int sure = 0;
	int i=0; // kuyruga yazilacak kafa konumu
	int j=0;
	int baslangic; // bilgisayarin kuyruga yazmaya basladigi an
	
	string dosyain = "a.txt";
	ifstream dosya;
	dosya.open(dosyain.c_str());
	
	if (dosya.is_open()) {
		unsigned int sn, cn;	
		cout<<"PC kac saniyede kuyruga belge gonderir (sn) : ?"<<endl; cin>>sn;
		cout<<"Yazicinin bir sayfayi yazma hizi nedir? (cn): ?"<<endl; cin>>cn;
	  
		while(1==1){
			
			//PCnin sirasi geldiyse
			if(sure % sn == 0 && !dosya.eof()){
				//Kuyrukta yer varsa yaz
				if(kuyrukta_yer_var_mi()){ 
					kuyruga_yazma(i,dosya);
					cout<< sure << "sn - Pc kuyruga yazdi - \t" << kuyruk[i].b_yolu <<endl;
					i++; // kuyruktaki bir sonraki elemanin yerini belirttik	
					dosya_sayisi++;//ekledigimiz dosya sayisi
								
				}
				else{
					cout<<"PC kuyruga yazamadi.\n";
				}
			}
			
			//yazicinin okumasi
			if(yazici_musait && kuyruk[0].b_yolu.length()!=0){// kuyrukta bir dosya var mi
			
				temp=kuyruk[0];	//kuyruktan veri al,tempe tasi
				
				cout<< sure <<"sn - Yazici kuyruktan okudu - \t" << temp.b_yolu << endl;
				//kuyruktan sil
				slide(i); 
				i--; // kuyruktaki bir sonraki elemana yer belirttik
				yazici_musait=0;
				baslangic=sure;
			
			}
			
			if(sure == baslangic + temp.sayfa_sayisi*cn && temp.b_yolu.length()!=0){
				cout<< sure << "sn - Yazici belge yazdi -\t" << temp.b_yolu <<endl;
				yazici_musait=1;
				yazilmis_dosya_sayisi++;
				if(yazici_musait && kuyruk[0].b_yolu.length()!=0){ // kuyrukta bir dosya var mi
					
					temp=kuyruk[0];//kuyruktan veri al tempe tasi
					
					cout<< sure <<"sn - Yazici kuyruktan okudu - \t" << temp.b_yolu << endl;
					//kuyruktan sil
					slide(i); 
					i--; 
					yazici_musait=0;
					baslangic=sure;
			
				}
			}
		
			if(dosya_sayisi == yazilmis_dosya_sayisi && dosya.eof()){	//yazdigimiz dosya sayisi a.txt dosyanin satir sayisina esitse hepsini yazmisiz demektir
				cout<<"Butun dosyalari yazdik..."<<endl;
				break;
			}
			sure = sure + 1;
		}
	}
   	dosya.close(); 
   	return 0;
}
   	

  
 
	
