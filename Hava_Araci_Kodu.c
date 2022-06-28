#include<stdio.h>
#include "instrumented.h"

int armDisarm1();
int ucus();
int yukselmeModu(int enlem, int boylam, float hiz);
int hareketKarari(int enlem, int boylam,float hiz);
int hareketKarari2(int enlem, int boylam,float hiz);
int gorevModu(int hedefEnlem, int hedefBoylam,float hiz);
int inisModu(int enlem, int boylam,float hiz);
int armDisarm2();


int main(int argc, char** argv)
{ Log5();
	int b;
	printf("Baglanti kodunu girin = "); 
	scanf("%d", &b);
	if( b == 1115 )
	{	Log1();
		printf("200: BAGLANTI KODU DOGRU \tISTEK BASARILI\n"); 
		Log6();statement(); armDisarm1();}
	else
	{	Log1();
		printf("404: BAGLANTI KODU YANLIS \n");
		Log6(); kapsam();  return 0;}}

int armDisarm1()
{Log5();
	int s;
	bool arm = false, disarm = true;
	int enlem = 0, boylam = 0;
	float hiz = 0;
	printf("Ucus'a hazir ise 1 e basin = ");
	scanf("%d", &s);
	if (s == 1)
	{	Log1();
		bool arm = true;
		bool disarm = false;
		printf("arm = %s\n", arm ? "true" : "false");
		Log6();statement(); yukselmeModu(enlem,boylam,hiz);}
	else
	{	Log1();
		printf("Ucus gerceklestirilemez!");
        Log6();kapsam(); return 0;}}

int yukselmeModu(int enlem, int boylam, float hiz)
{Log5();
	int modSecimi, t = 2, hedefEnlem, hedefBoylam;
	float konum, alinacakMesafe;
	float alinanMesafe, ivme, alinanYol, hedefMesafe;
	konum = sqrt(pow(enlem, 2)+pow(boylam, 2));
	while (true)
	{	Log2();
		printf("Hedef noktasinin koordinatlarini girin = ");
		scanf("%d %d", &hedefEnlem, &hedefBoylam);
		if(hedefEnlem>enlem && hedefBoylam>boylam)
		{	Log1();
			printf("1. Guided Modu\n");
			printf("2. Stabilize Mod\n");
			printf("Yukselme islemi hangi modda yapilacak = ");
			scanf("%d", &modSecimi);
			if(modSecimi == 1 || modSecimi == 2)
			{	Log1(); 
				switch(modSecimi)
				{	
					case 1:Log6();statement();
						Log5(); Log4();
						printf("Guide modu secildi.");
						printf("\nPlanlanan hedef noktasi = (%d, %d)", hedefEnlem, hedefBoylam);
						printf("\nAnlik konum = (%d, %d)", enlem, boylam); 
						//printf("\n Alinacak mesafe =(%d, %d)", (hedefEnlem-enlem), (hedefBoylam-boylam));
						alinacakMesafe = sqrt(pow(hedefEnlem-enlem,2)+pow(hedefBoylam-boylam,2));
						printf("\nAlinacak mesafe %2.1f\n", alinacakMesafe);
						for (t=2; t<=6; t=t+2)
						{	Log3();
							if(t == 2 || t == 4)
							{	Log1();
								ivme = alinacakMesafe/pow(14-t,2);
								hiz = ivme*t;
								printf("hiz = %2.1f\n", hiz);
								alinanYol = hiz*t;
								alinacakMesafe = alinacakMesafe-alinanYol;
								printf("Kalan Mesafe = %2.1f\n", alinacakMesafe);	
								
							}
							else
							{	Log1();
								printf("Kalan mesafe %2.1f ve %2.1f hiz ile tamamlandi. \n", alinacakMesafe,  hiz+5);
								sleep(2);
								printf("Yukselme islemi tamamlandi. Bir sonraki adimi secin. \n");
								enlem = hedefEnlem;
								boylam = hedefBoylam;
								Log6();statement(); hareketKarari(enlem, boylam, hiz);}sleep(1.5); }break;	
					case 2: Log6();statement();
						Log5(); Log4();
						hiz = 10;
						printf("Stabilize mod secildi.\n");
						printf("Alinacak mesafe = (%d, %d)", (hedefEnlem-enlem), (hedefBoylam-boylam));
						alinacakMesafe = sqrt(pow(hedefEnlem-enlem,2)+pow(hedefBoylam-boylam,2));
						t = alinacakMesafe / hiz;
						sleep(3);
						printf("\n%2.1f hiz ile %d surede belirlenen konuma ulasildi.\n", hiz, t);
						sleep(1);
						printf("Yukselme islemi tamamlandi. Bir sonraki adimi secin.\n");
						Log6();statement(); hareketKarari(hedefEnlem, hedefBoylam, hiz);break;}break;}
			else
			{	Log1();
				printf("Yanlis mod secimi!\n");
				printf("Lutfen tekrar mod secimi yapin.\n");
			} 
		}
		else
		{	Log1();
			printf("Yukselme modu!\n");
			printf("Mevcut konumdan buyuk bir konum girin!\n");
		}
	}
	
}
int hareketKarari(int enlem,int boylam,float hiz)
{Log5();
	int a;
	while (true)
	{	Log2();
		printf("1. Inis Modu\n");
		printf("2. Gorev Mod\n");
		printf("Hangi modda ucus yapilacak = ");
		scanf("%d", &a);
		if(a == 1 || a == 2)
		{	Log1();
			switch(a)
			{	
				case 1:Log6();statement();
					Log5();Log4();
					Log6();statement(); inisModu(enlem, boylam, hiz); break;
				case 2:Log6();statement();
					Log5(); Log4();
					Log6();statement(); gorevModu(enlem, boylam, hiz); break;}break;}
		else
			Log1();
			printf("Yanlis mod secimi!\n");
			printf("Lutfen tekrar mod secimi yapin.\n");
	}
}

int gorevModu(int enlem,int boylam,float hiz)
{Log5();
	int modSecimi, enlemYeni, hedefBoylam;
	float konum, alinacakMesafe, t;
	int yariCap, modSecimi2;
	printf("Gorev modu secildi.\n");
	while(true)
	{	Log2();
		printf("1. AltHold Modu\n");
		printf("2. Circle Mod\n");
		printf("Gorev hangi modda yapilacak = ");
		scanf("%d", &modSecimi);
		if(modSecimi == 1 || modSecimi == 2)
		{	Log1();
			switch(modSecimi)
			{	
				case 1: Log6();statement();
					Log5(); Log4();
					printf("AltHold Modu secildi.\n");
					printf("Hedef enlem noktasini girin = ");
					scanf("%d", &enlemYeni);
					printf("Planlanan hedef noktasi = (%d, %d)\n", enlemYeni, boylam);
					printf("Anlik konum = (%d, %d)\n", enlem, boylam); 
					printf("Alinacak mesafe = (%d, %d)\n", (abs(enlemYeni-enlem)), 0);
					sleep(5);
					alinacakMesafe = sqrt(pow(enlemYeni-enlem,2));
					t = alinacakMesafe / hiz;
					printf("\nHedef Noktasina %2.1f hiz ile %2.1f surede ulasildi.", hiz, t);
					printf("Gorev adimi tamamlandi. Bir sonraki hareket kararini secin.\n");
					sleep(1);
					enlem = enlemYeni;
					Log6();statement();hareketKarari2(enlem, boylam, hiz); break;
				case 2: Log6();statement();
					Log5(); Log4();
					printf("Circle Modu secildi.\n");
					printf("Circle merkezi (%d, %d)\n", enlem, boylam);
					while(true)
					{	Log2();
						printf("Yaricap 25'den kucuk olmali.\n");
						printf("Gorev icin cizilecek dairenin yaricapini girin = ");
						scanf("%d", &yariCap);
						if(yariCap<25)
						{	Log1();
							printf("Circle birinci ceyregi =  (%d, %d)", enlem, boylam+yariCap);
							sleep(2);
							printf("\nCircle ikinci ceyregi =  (%d, %d)", enlem+yariCap, boylam);
							sleep(2);
							printf("\nCircle ucuncu ceyregi =  (%d, %d)", enlem, boylam-yariCap);
							sleep(2);
							printf("\nCircle dorduncu ceyregi =  (%d, %d)", enlem-yariCap, boylam);
							sleep(2);
							printf("\n\nGorev adimi tamamlanmistir. Bir sonraki adimi seciniz.\n");
							enlem = enlem-yariCap;
							Log6();statement();hareketKarari2(enlem, boylam, hiz); break;}
						else
						{	Log1();
							printf("\nYaricap siniri gecildi. Tekrar yaricap girin.\n");
						}
					}
					break;
			}
			break;
		}
		else
			Log1();
			printf("\nYanlis mod secimi!\nLutfen tekrar mod secimi yapin.\n");
	}
}
int hareketKarari2(int enlem,int boylam,float hiz)
{Log5();
	int a;
	while (true)
	{	Log2();
		printf("1. Yukselme Modu \n");
		printf("2. Inis Modu \n");	
		printf("Hangi modda ucus yapilacak = ");
		scanf("%d", &a);
		if(a == 1 || a == 2)
		{	Log1();
			switch(a)
			{	
				case 1: Log6();statement();
					Log5(); Log4();
					Log6();statement();yukselmeModu(enlem, boylam, hiz); break;
				case 2: Log6();statement();
					Log5();Log4();	
					Log6();statement(); inisModu(enlem, boylam, hiz); break;}break;}
		else
			Log1();
			printf("\nYanlis mod secimi! \tLutfen tekrar mod secimi yapin.");	
	}
}

int inisModu(int enlem,int boylam,float hiz)
{Log5();
	int modSecimi,t;
	float alinacakMesafe;
	float konum;
	int hedefEnlem, hedefBoylam, a;
	float yeniHiz, ivme, alinanYol, hedefMesafe;
	bool arm = false, disarm = true;
	printf("Inis Moduna gecildi.\n");
	while(true)
	{	Log2();
		printf("1. RTL Modu\n");
		printf("2. Stabilize Mod\n");
		printf("3. Manuel Mod\n");
		printf("4. Guided Mod\n");
		printf("Inis islemi hangi modda yapilacak = ");
		scanf("%d\n ", &modSecimi);
		if(modSecimi == 1 || modSecimi == 2 || modSecimi == 3 || modSecimi == 4)
		{	Log1();
			switch(modSecimi)
			{	
				case 1:Log6();statement();
					Log5();Log4();
					hedefEnlem = 0; hedefBoylam = 0;
					printf("RTL Modu secildi. \n");
					printf("\nPlanlanan hedef noktasi = (%d, %d)", hedefEnlem, hedefBoylam);
					printf("\nAnlik konum = (%d, %d)", enlem, boylam); 
					printf("\nAlinacak mesafe =(%d, %d)", enlem, boylam);
					sleep(3);
					printf("\nHedefe ulasildi.\n");
					printf("Ucus Tamamlandi.\n");
					printf("\ndisarm = %s\n", disarm ? "true" : "false");
					Log6(); kapsam(); break;			
				case 2: Log6();statement();
					Log5();Log4();
					hedefBoylam = 0;
					printf("Stabilize mod secildi.\n");
					printf("\nPlanlanan hedef noktasi = (%d, %d)", enlem*2, hedefBoylam);
					printf("\nAlinacak mesafe = (%d, %d)", enlem, boylam);
					alinacakMesafe = sqrt(pow(enlem*2,2)+pow(boylam,2));
					t = alinacakMesafe / hiz;
					sleep(3);
					printf("\n%2.1f hiz ile %d surede belirlenen konuma ulasildi.", hiz, t);
					printf("\nUcus Tamamlandi.");
					printf("\ndisarm = %s\n", disarm ? "true" : "false");
                    Log6(); kapsam(); break;	
				case 3: Log6();statement();
					Log5(); Log4();
					hedefBoylam = 0;
					printf("Manuel mod secildi.\n");
					while(true)
					{	Log2();
						if(boylam<70)
						{	Log1();
							if(hiz<20)
							{	Log1();
								if(boylam-6>=hedefBoylam)
								{	Log1(); 
						   			printf("\nEnlem = %d, Boylam = %d\n ", enlem+10,boylam-6);
						   			enlem=enlem+10;
						   			boylam=boylam-6;									
								}
								else
								{   Log1();
						   			printf("\nEnlem = %d, Boylam = %d\n ",enlem+10,hedefBoylam);
						   			enlem=enlem+10;
						   			boylam=hedefBoylam;
						   			sleep(2);
						   			printf("Ucus Tamamlandi.\n");
									printf("\ndisarm = %s\n", disarm ? "true" : "false");
									Log6();kapsam(); break;	}}
							else
							{	Log1();
								if(boylam-10>=hedefBoylam)
								{	Log1();       
						   			printf("\nEnlem = %d, Boylam = %d\n ", enlem+15,boylam-10);
						   			enlem=enlem+15;
						   			boylam=boylam-10;
								}
								else
								{	Log1();
						   			printf("\nEnlem = %d, Boylam = %d\n ", enlem+15,hedefBoylam);
						   			enlem=enlem+15;
						  			boylam=hedefBoylam;
						   			sleep(2);
						   			printf("Ucus Tamamlandi.\n");
									printf("\ndisarm = %s\n", disarm ? "true" : "false");
      								Log6();kapsam();break;}}}
						else
						{	Log1();
							if(hiz>=0 && hiz<70)
							{	Log1();
								if(boylam-5>=hedefBoylam)
								{   Log1();    
						   			printf("\nEnlem = %d, Boylam = %d\n ", enlem+8,boylam-5);
						   			enlem=enlem+8;
						   			boylam=boylam-5;
								}
								else
								{   Log1();    
						   			printf("\nEnlem = %d, Boylam = %d\n ", enlem+8,hedefBoylam);
						   			enlem=enlem+8;
						   			boylam=hedefBoylam;
						   			sleep(2);
						   			printf("Ucus Tamamlandi.\n");
									printf("\ndisarm = %s\n", disarm ? "true" : "false");
									Log6();kapsam(); break;}}
							else
							{	Log1();
								if(boylam-7>=hedefBoylam)
								{   Log1();    
						  			printf("\nEnlem = %d, Boylam = %d\n ", enlem+12,boylam-7);
						   			enlem=enlem+12;
						   			boylam=boylam-7;
								}
								else
								{   Log1();    
						   			printf("\nEnlem = %d, Boylam = %d\n ", enlem+12,hedefBoylam);
						   			enlem=enlem+12;
						   			boylam=hedefBoylam;
						   			sleep(2);
						   			printf("Ucus Tamamlandi.\n");
									printf("\ndisarm = %s\n", disarm ? "true" : "false");
									Log6(); kapsam();break;}}}
						konum=sqrt(pow(enlem,2)+pow(boylam,2));
						hiz=konum/2;
						sleep(1);
					}		
					break;
				case 4:Log6();statement();
					Log5(); Log4();
					hedefEnlem = enlem*7/4;
					hedefBoylam = 0;
					printf("Guide modu secildi.\n");
					printf("\nPlanlanan hedef noktasi = (%d, %d)", hedefEnlem, hedefBoylam);
					printf("\nAnlik konum = (%d, %d)", enlem, boylam); 
					//printf("\n Alinacak mesafe =(%d, %d)", (hedefEnlem-enlem), (hedefBoylam-boylam));
					alinacakMesafe = sqrt(pow(hedefEnlem-enlem,2)+pow(hedefBoylam-boylam,2));
					printf("\nAlinacak mesafe %2.1f", alinacakMesafe);
					for (t=2; t<=6; t=t+2)
					{	Log3();
						if(t == 2 || t == 4)
						{	Log1();
							//printf("if- else Kapsami: %d",sum);
							ivme = alinacakMesafe/pow(14-t,2);
							hiz = ivme*t;
							printf("\nhiz = %2.1f", hiz);
							alinanYol = hiz*t;
							alinacakMesafe = alinacakMesafe-alinanYol;
							printf("\nKalan Mesafe = %2.1f", alinacakMesafe);							
						}
						else
						{	Log1();
							printf("\nKalan mesafe %2.1f ve %2.1f hiz ile tamamlandi. ", alinacakMesafe,  hiz+5);
							sleep(2);
							printf("Ucus Tamamlandi.\n");
							printf("disarm = %s\n", disarm ? "true" : "false");
      						Log6(); kapsam();break;}sleep(1.5); }break;}break;}
		else
		{	Log1();
			printf("Yanlis mod secimi!\n");
			printf("Lutfen tekrar mod secimi yapin.\n");
		}									
	}
}

