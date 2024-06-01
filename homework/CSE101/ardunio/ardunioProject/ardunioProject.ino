#define ledPin 13
#define buttonPin 4

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin,INPUT);
  
}

void loop() 
{
  
    char selection;              // Operasyon degiskeni
    
    if( Serial.available())
    {
        selection=Serial.read();     // C den gelen komutu okuyor
    }
  //====================================================================

    if(selection == '1')
    {
        digitalWrite(ledPin,HIGH);
        
    }
    else if(selection == '2')
    {
        digitalWrite(ledPin,LOW);
        
    }
    else if(selection == '3')
    {
        led_Blink();
        
    }
    else if(selection == '4')
    {
        square_func();
    }

    else if(selection == '5')
    {
        PushButton();
    }
       
}

void led_Blink()
{
  int i=0;

        for(i=0;i<3;i++)
        {
            digitalWrite(ledPin,HIGH);
            delay(1000);

            digitalWrite(ledPin,LOW);
            delay(1000);
        }
}

void square_func()
{
    int Number=0;
    int k=1;
  
    while(true)
    {
    
     if(Serial.available())           // Baglanti yolunu kontrol ediyor
     {       
                
        delay(100);         
        String Data = Serial.readString();   // C den gelen komutu okuyor            
        delay(10);
                    
        Number = Data.toInt();       //Stringi integer a ceviriyor
        Number=Number*Number;        //Sayinin karesini aliyor
      
        Serial.println(Number);      //Okunacak degeri yazdiriyor
              
        if(Number>0 || k+Number == 1)
        {   //C den bir deger okundugunda dongunun kirilmasi icin gerkeli sartlari iceren fonk.
           break;
        }        
     }
  }
}

void PushButton()
{

     int count=0;        //sayac
     int pushButton=0;  //Ilk sifir atandi cunku ilk durum not push durumu
     int dizi[2];       // Farki gormek icin (0 dan 1 e donusumu) 
        
      while(1)
      {
          
         dizi[0] = pushButton;         //ilk karakteri okuyor
         pushButton = digitalRead(buttonPin);
         dizi[1] = pushButton;         //Degisim olursa yani butona basilirsa 1 basilmassa 0 aliyor
     
         if(dizi [0] != dizi[1])      //Digitalread deki degisim olursa fonkicine giriyor  (0 dan 1) veya(1 den 0)a
         {         
             if(dizi[1]==0)         // eger degisim 0 dana 1 e ise count 1 artiriyor
             {            
                 count ++;
                 Serial.println(count);  //Serial monitore c nin almasi icin yazdiriyor
              }       
          }
          delay(100);     //Stabilite icin
       }
}
