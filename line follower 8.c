#include<avr/io.h>
#include<util/delay.h>
void lcdcmd(char x)
{
	
	PORTD=x;
	PORTC=0b00000100;
	_delay_ms(100);
	PORTC=0b00000000;
	_delay_ms(100);
}

void lcddata(char x)
{
	PORTD=x;
	PORTC=0b00000101;
	_delay_ms(100);
	PORTC=0b00000001;
	_delay_ms(100);
	
}
void display(char y[])
{
	int i;
	for(i=0;y[i]!='\0';i++)
	
	{
		lcddata(y[i]);
	}
}

void main()
{
	DDRB=0b11111111;
	DDRC=0b00000000;
	DDRD=0b11111111;
	while(1)
	{
		lcdcmd(0x38);
		lcdcmd(0x0E);
		if(PINC==0b00000011)
		{
			PORTB=0b11111001;
			display("FORWARD");
			lcdcmd(0x01);
		}
		if(PINC==0b00000010)
		{
			PORTB=0b11111000;
			display("RIGHT");
			lcdcmd(0x01);
		}
		if(PINC==0b00000001)
		{
			PORTB=0b11110001;
			display("LEFT");
			lcdcmd(0x01);
		}
		
		if(PINC==0b00000000)
		{
			PORTB=0b11110000;
			display("STOP");
			lcdcmd(0x01);
		}
	}
}