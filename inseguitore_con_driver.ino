
int val;                  // valore letto in ingresso (range 0-1023)
int pos;                  // posizione del servo
int tolleranza=20;        // isteresi 
int partitore_pin = A0;   // pin di lettura tensione del partitore

void setup()
{
  pinMode(partitore_pin,INPUT);   // imposto il pin del partitore come ingresso per leggere il valore della tensione
  Serial.begin(9600);             // attivo la comunicazione seriale 
  pos = 1300;                     // imposto il servo in posizione centrale
}

void loop() 
{ 
  val = analogRead(0);            // leggo il valore del partitore (range 0-1023  corrispondente a 0-5 Volt)
  if (val> 512+tolleranza){       // se il partitore legge PIU di 2.5 Volt + la tolleranza
    if (pos < 2500){              // se non sono arrivato al MASSIMO del movimento del servo
      pos += 10;                  // INCREMENTO il valore della posizione del servo
      }
    }
  if (val< 512-tolleranza){        // se il partitore legge MENO di 2.5 Volt + la tolleranza
    if (pos > 500){                // se non sono arrivato al MINIMO del movimento del servo
      pos -= 10;                   // RIDUCO il valore della posizione del servo
      }
    }
    // costruzione stringa da inviare al DRIVER che comanda i servo
    String uno = "#1P";           // indico al driver che voglio comandare il servo che è collegato alla porta 1 del driver
    String due = "T1000";         // indico al servo che il movimento per raggiungere la nuova posizione è da compiere in 1000 millisecondi
    
    String stringThree =  uno + pos + due; //unisco le stringhe di comando per inviarle tuttte assieme
    Serial.println (stringThree);          // invio le stringhe di comando
    delay (50);                            // attendo 50 millisecondi prima di ripetere il ciclo
} 

