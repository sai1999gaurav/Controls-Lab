#define sel1 38
#define sel2 39
#define rst_ 40
#define clk 12
#define sc_factor 3.14/1000

int alpha, theta, pre_alpha, pre_theta, v_max = 200 ;
float d_theta, d_alpha;
byte alpha1, alpha2, theta1, theta2;
// -k = 31.6228 -179.2687    9.6832  -23.9589
// 10.0000 -124.4871    5.0519  -16.5453
//1.0000  -21.0225    0.5686   -2.5916
//double k1 = -5.014844822490342,       k2 = 1.160506665162347e+02,       k3 = -5.564315866779011,       k4 = 15.411332502354945,
float k1 = 11.54, k2 = -124.4871, k3 = 5.0519, k4 = -16.54, power, d_t = 5, p_scale = 30;
void setup()
 {
  pinMode(sel1, OUTPUT);
  pinMode(sel2, OUTPUT);
  pinMode(rst_, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  TCCR1B=0x01;
  analogWrite(clk, 127);

  digitalWrite(rst_, LOW);
  delay(1000);
  digitalWrite(rst_, HIGH);

 alpha = 0;
 theta=0;
 pre_alpha = 0;
 pre_theta = 0;
 DDRC=0b00000000;
 DDRA=0b00000000;

  Serial.begin(9600);

}


void loop()
 {
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
  d_theta = (theta - pre_theta)/(d_t*1e-3);
  d_alpha = (alpha - pre_alpha)/(d_t*1e-3);
  power = (k1*theta + k2*alpha + k3*d_theta + k4*d_alpha)*sc_factor;
  //Serial.print(power*p_scale);
  //Serial.print(',');
  //Serial.println(alpha);
  //if (power < -256) power = 256;
  //if (power > 255) power = 255;
  //v_max = (int) power/p_scale;
  if(alpha < 0)
  {analogWrite(8, min(v_max,power*p_scale));
  digitalWrite(9, LOW);}
  if (alpha > 0)
  {analogWrite(9, min(v_max,-power*p_scale));
  digitalWrite(8, LOW);
  }
   pre_alpha = alpha;
  pre_theta = theta;
   // analogWrite(8, 128 + v_max);
  //analogWrite(9, 127 - v_max);

  delay(d_t-2);
}
