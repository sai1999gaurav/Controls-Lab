#define sel1 38
#define sel2 39
#define rst_ 40
#define clk 12

#define mot_plus 8
#define mot_minus 9

int alpha;
byte alpha1, alpha2;
int theta;
byte theta1, theta2;
float u =0;
int prev_alpha = 0;
int prev_theta = 0;
int d_theta = 0;
int d_alpha = 0;

void setup()
 {
  pinMode(sel1, OUTPUT);
  pinMode(sel2, OUTPUT);
  pinMode(rst_, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(mot_plus, OUTPUT);
  pinMode(mot_minus, OUTPUT);
//  pinMode(8, OUTPUT);
//  pinMode(9, OUTPUT);
  TCCR1B=0x01;
  analogWrite(clk, 127);
//
  digitalWrite(rst_, LOW);
  delay(1000);
  digitalWrite(rst_, HIGH);
//
 alpha = 0;
 theta = 0; 
// int prev_alpha = 0;
// int prev_theta = 0;
// int d_theta = 0;
// int d_alpha = 0;
 DDRC=0b00000000;

 Serial.begin(9600);

}
/*
u max = 276222.53
*/
void loop()
 {

//  k = (-1.4142   46.7409   -1.4462    6.1010);
//-1.4142   46.7701   -1.4465    6.1019
//-10.0000  504.9633  -16.8895   68.0389
//-10.0000  768.9352  -25.1031  103.7566
//-3.1623  247.7668   -7.9631   33.2295
float k1 =0;
float k2 =0;
float k4 =0;
float k3 =0;

k1 =-3.1623;


k2 =93.0632;


k3 =-3.1468;


k4 =12.2959;

//  u = theta*(-10) + alpha*(768.9352) + d_theta*(-25.1031) + d_alpha*(103.7566);
  u = theta*(k1) + alpha*(k2) + d_theta*(k3) + d_alpha*(k4);
  u = -u;
//  Serial.print("u: ");
//  Serial.println(u);
if(u<0){
  if(u<-255) u=-255;
  analogWrite(mot_plus, -u);
  analogWrite(mot_minus, 0);
  delay(100);
}
else{
  if(u>255) u=255;
  analogWrite(mot_plus, 0);
  analogWrite(mot_minus, u);
  delay(100);
}
  
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, LOW);
  alpha1=PINC;
  theta1=PINA;
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, LOW);
  alpha2=PINC;
  theta2=PINA;
  alpha=word(alpha2, alpha1);
  theta=word(theta2, theta1);

  d_theta = theta - prev_theta;
  d_alpha = alpha - prev_alpha;
  prev_theta = theta;
  prev_alpha = alpha;
//  Serial.print("alpha: ");
//  Serial.println(alpha);
//  Serial.print("theta: ");
//  Serial.println(theta);
//  Serial.print("d_alpha: ");
//  Serial.println(d_alpha);
//  Serial.print("d_theta: ");
//  Serial.println(d_theta);


}
