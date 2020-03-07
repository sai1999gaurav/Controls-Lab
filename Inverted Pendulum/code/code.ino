#define sel1 38
#define sel2 39
#define rst_ 40
#define clk 12
#define sc_fac 0.5

int alpha, theta, pre_alpha = 0, pre_theta = 0, v_max = 250;
float d_theta, d_alpha;
byte alpha1, alpha2, theta1, theta2;
// -k = 31.6228 -179.2687    9.6832  -23.9589
float k1 = 100.6228, k2 = -300.0092, k3 = 59.9138, k4 = -123.4082, power, d_t = 20, p_scale = 5;
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
 DDRC=0b00000000;

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
  power = (k1*theta + k2*alpha + k3*d_theta + k4*d_alpha)*sc_fac;
  Serial.println(power);
  if(alpha < 0)
  {analogWrite(8, min(v_max,power*p_scale));
  digitalWrite(9, LOW);}
  else
  {analogWrite(9, min(v_max,-power*p_scale));
  digitalWrite(8, LOW);
  }
  pre_alpha = alpha;
  pre_theta = theta;
  delay(d_t);
}
