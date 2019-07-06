#include <Servo.h>

#define pSrvLegL 5
#define pSrvLegR 6
#define pSrvFootL 10
#define pSrvFootR 11
#define pSrvSwitch 2
#define nn -9999      // "null"

Servo srvLegL;
Servo srvLegR;
Servo srvFootL;
Servo srvFootR;

// Set servo positions
// ===================
void set(int ll, int lr, int fl, int fr, int dl) {
  if (ll > nn) srvLegL.write(90-ll);
  if (fl > nn) srvFootL.write(90+fl);
  if (lr > nn) srvLegR.write(90+lr);  
  if (fr > nn) srvFootR.write(90-fr);
  delay(dl*1.1);
}

// Init
// ===================
void setup() { 
  srvLegL.attach(pSrvLegL);
  srvLegR.attach(pSrvLegR); 
  srvFootL.attach(pSrvFootL);
  srvFootR.attach(pSrvFootR);
  pinMode(pSrvSwitch, OUTPUT);
  delay(500);
  digitalWrite(pSrvSwitch, HIGH);
  set(0,0,0,0,0);
  delay(2000);
}

//  Dances
// ===================
void dnc1() {
  for (int i = 1; i <= 4; i++) { 
    for (int j = 1; j <= 3; j++) { 
      set(nn,nn,40, 0,120);
      set(nn,nn, 0,40,120);
      set(nn,nn,10, 0,120);  
      set(nn,nn, 0,10,120);  
      set(nn,nn,nn, 0,500);
    }
    set(nn,nn,40,40,250);
    set( 0, 0, 0, 0,600);
  }   
}

void dnc2() {
  for (int i = 1; i <= 3; i++) { 
    for (int j = 1; j <= 3; j++) {
      set(-10,-10, 0, 0,90);
      set(  0,  0,nn,nn,90);
      set(-10,-10,nn,nn,90);
      set(  0,  0,nn,nn,90);
      set( 10, 10,nn,nn,90);
    } 
    set(  0,  0,40,40,250);
    set( nn, nn, 0, 0,250);
  }
  for (int j = 1; j <= 4; j++) {
    set(  0,  0,40,40,250);
    set( nn, nn, 0, 0,250);
  }
}

void dnc3() {
  int x = 1;
  int x1 = -15;
  int x2 = 15;
  for (int i = 1; i <= 240; i++) {    
    set(x1,x1,x2,x2,35);
    if (x1 > 15) x = -1;
    if (x1 < -15) x = 1;
    x1 = x1 + x;
    x2 = x2 + x;
  } 
}

//  Walks
// =================
void wlk1() {
  int dl = 25;
  set(10,-10,nn,nn,0);
  for (int l = 1; l <= 2; l++) {
    for (int j = 1; j <= 20; j++) {
      srvFootL.write(80+(j*3));
      srvFootR.write(80+j);
      delay(dl);
    }    
    for (int i = 1; i <= 3; i++) {     
      for (int j = 1; j <= 20; j++) {
        srvFootL.write(140-(j*4));
        srvFootR.write(100-(j*3));
        delay(dl);
      }
      for (int j = 1; j <= 20; j++) {
        srvFootL.write(60+(j*4));
        srvFootR.write(40+(j*3));
        delay(dl);
      }    
    }
    set(  0,  0,40,40,250);
    set( nn, nn, 0, 0,250);
    set(-10,10,nn,nn,0);
    for (int j = 1; j <= 20; j++) {
      srvFootL.write(80-j);
      srvFootR.write(80-(j*3));
      delay(dl);
    }    
    for (int i = 1; i <= 3; i++) {         
      for (int j = 1; j <= 20; j++) {
        srvFootL.write(60+(j*4));
        srvFootR.write(40+(j*3));
        delay(dl);
      }
      for (int j = 1; j <= 20; j++) {
        srvFootL.write(140-(j*4));
        srvFootR.write(100-(j*3));
        delay(dl);
      }    
    }  
    set(  0,  0,40,40,250);
    set( nn, nn, 0, 0,250);
  }
}

void wlk2() {
  for (int i = 1; i <= 4; i++) {
    for (int i = 1; i <= 3; i++) {
      set(-10, 10, 20,-10,200);
      set(-20, 20,  0,  0,300);
      set( 10,-10,-10, 20,200);
      set( 20,-20,  0,  0,300);
    }
    set(  0,  0,  0,  0,500);
    set(  0,  0,40,40,250);
    set( nn, nn, 0, 0,250);
  }
}

//  Balances
// ===================
void bln1() {
  int dl = 35; 
  for (int i = 1; i <= 2; i++) { 
    for (int j = 1; j <= 45; j++) {
      srvFootL.write(80-j);
      srvLegL.write(80+(j/2));
      srvLegR.write(80+(j/2));
      if ( j <= 20) srvFootR.write(80-(j*3));    
      delay(dl);
    } 
    set(nn,nn, nn, 0,800);
    set(nn,nn,-45,-20,200);
    set(nn,nn,-40, 20,200);
    set( 0, 0, 0, 0, 400);
    for (int j = 1; j <= 45; j++) {
      srvFootR.write(80+j);
      srvLegL.write(80-(j/2));
      srvLegR.write(80-(j/2));
      if ( j <= 20) srvFootL.write(80+(j*3));     
      delay(dl);
    } 
    set(nn,nn,  0, nn,800);
    set(nn,nn,-20,-45,200);
    set(nn,nn, 20,-40,200);
    set( 0, 0, 0, 0, 400);
  }
}

void bln2() {
  for (int i = 1; i <= 2; i++) {
    set( 0, 0, 20, 20,100);
    set( 0, 0,  0,  0,400);
    set(nn,nn,-25, 50,200);
    set(nn,nn,-30, 50,300);
    set(nn,nn, nn,  0,100);
    set(nn,nn, nn, 20,100);
    set(nn,nn, nn,  0,100);
    set(nn,nn, nn, 20,100);
    set(nn,nn, nn,  0,500);
    set( 0, 0,  0,  0,500);
    set(nn,nn, 50,-25,200);
    set(nn,nn, 50,-30,300);
    set(nn,nn,  0, nn,100);
    set(nn,nn, 20, nn,100);
    set(nn,nn,  0, nn,100);
    set(nn,nn, 20, nn,100);
    set(nn,nn,  0, nn,500); 
  }
} 

//  Tapping
// ===================
void tap1() {
  for (int i = 1; i <= 4; i++) {
    set(nn,nn,nn,-10,80);
    set(nn,nn,nn, 0,420);
  }
}

void tap2() {
  for (int i = 1; i <= 8; i++) {
    set(nn,nn,20,20,100);
    set(nn,nn, 0, 0,400);
  }
}

void tap3() {
  for (int i = 1; i <= 4; i++) {    
    for (int j= 1; j <= 3; j++) {
      set(nn,nn,10*j,10*j,1000);    
    }
    set(0,0,0,0,1000);
  }  
}

void loop() {
  tap1();
  while (true) {       
    dnc1();
    dnc2();
    wlk1();
    dnc1();    
    wlk2();  
    bln2();
    wlk1();
    tap2();
    dnc3();
    set(0,0,0,0,1000);
    tap3();
    wlk2();
  }
}
