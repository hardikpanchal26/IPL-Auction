/*
  Software           : IPL AUCTION AUDITORIAL DESK
  Software Developer : Hardik Panchal -> at the age of 17 years
  Time period        : It took me 2 hours daily in 3 months to develop this software

					THIS IS MY FIRST SOFTWARE EVER PRODUCED

  Two Text Files are required in BIN
   1) accipl.txt    -> Create an empty file of this name
   2) players.txt   -> This file contains all Player's Records
*/

#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#define nil{textcolor(0);gotoxy(2,3);cprintf(" "); gotoxy(2,3);}
#define b0 {textbackground(0);}

char key;
int ex=0;
char filename[15];
unsigned long initialbudget;
class frames
{ protected:
  void header ();
  void box    (int);
  void footer (char*);
  void getee  (char*,int,char);
  void convert(char a,long &b);
} frame;                            // class frames ends

class main_menu : protected frames
{ public:
  char mchoice;
  void menu();
  void action();
  void account_details();
  void retain();
  void auction();
  void records();
  void smart();
  void add_edit();
  void team();
  void help();
  void exitapp();
} menu;                               // Class Main menu ends

void welcome()
{gotoxy(34,12); textcolor (10);     cprintf("WELCOME TO");
 gotoxy(26,13); textcolor (12);     cprintf("IPL AUCTION AUDITORIAL DESK");
 gotoxy(69,24); textcolor(15+128);  cprintf("Press ENTER"); nil
}
void frames::convert(char a,long &b)
{for (int ie=0; ie<11; ++ie) { if(a==(48+ie)) {b=ie;} } } // convert() ends
void frames :: header()
{gotoxy(1,1); textbackground(4);
textcolor (1); cprintf("    ð");
textcolor(14); cprintf("                     IPL AUCTION AUDITORIAL DESK        ");
textcolor (1); cprintf("þ ");
textcolor (0); cprintf("Original Version ");
b0
}                                  // header()  ends

void frames :: footer (char array []="Press ESC to go to Main Menu")
{gotoxy(1,25); textbackground(4);
 textcolor(0); cprintf("INSTRUCTIONS : ");
 cprintf("                                                                ");
 gotoxy(16,25); textcolor(14); cprintf("%s", array);
 b0 }                                 // footer() ends

void frames::box(int color=1)
{gotoxy(1,2); textcolor(color);
 for ( int i=1; i<81; ++i) cprintf ("Í");
 for ( i=2; i<25; ++i) { gotoxy( 1,i); cprintf("º");
						 gotoxy(80,i); cprintf("º"); }
 gotoxy( 2,24); for ( i=1; i<=79; ++i) cprintf ("Í");
 gotoxy( 1,2 ); cprintf("É"); gotoxy(80,2 ); cprintf("»");
 gotoxy( 1,24); cprintf("È"); gotoxy(80,24); cprintf("¼");  char ch=4;
 gotoxy( 4,2 ); cprintf("<%c>",ch); ch=15;  gotoxy(5,24); cprintf("%c",ch);
 gotoxy( 77,2); cprintf("[]");
}                               // box() ends

void frames :: getee(char m[], int len,char replacechar = '`')
{ textcolor(15); for (int i=0; i<len; i++) {m[i]='\0';}
for ( i=0; i<len; i++)
{  m: m[i]=getch();
if (i==0 && (m[i]=='\b'|| m[i]==13 || m[i]==' ')) {m[i]='\0'; goto m; }
if (i==(len-1)) { if (m[i]==13) {m[i]='\0'; break;}
else if (m[i]==27) {m[i]='\0'; if (ex==1) {clrscr(); menu.exitapp();}
							   else       {menu.menu();} }
else if (m[i] == '\b') {m[i]='\0'; gotoxy(wherex()-1,wherey());  cout<<" ";
					   gotoxy(wherex()-1,wherey()); --i;goto m;}
					   else {m[i]='\0'; goto m;} }
else if (isalpha(m[i])||isdigit(m[i])||m[i]=='_'||m[i]==' ')
{if(replacechar=='`') {cprintf("%c",m[i]);}  else{cprintf("%c",replacechar);}}
else if (m[i] == '\b') {m[i]='\0'; gotoxy(wherex()-1,wherey());cout<<" ";
						gotoxy(wherex()-1,wherey()); --i;goto m; }
else if (m[i]==13) {m[i]='\0'; break;}
else if (m[i]==27) {m[i]='\0';
				   if(ex==1){clrscr(); menu.exitapp();} else{menu.menu();}}
else {m[i]='\0'; goto m;}}
}                                                // getee() ends

struct account_use
{ char uzname[30];
  char password[20];
  char team_name[30];
  char abbrev[6];
  unsigned long budget;
} obj,obj2;

class window1 : protected frames
{ public:
  void win1menu();
  void side    ();
  void create_account();
  void log_in();
  void rules();
} win1;

void window1 :: side()
{ textcolor(1); for (int i=2; i<25; i++)
				{gotoxy(1,i); cprintf("Û"); gotoxy(80,i); cprintf("Û");}
				for (int j=2; j<80; j++)
				{gotoxy(j,2); cprintf("ß"); gotoxy(j,24); cprintf("Ü");}
}                                          // side() ends

void window1 :: rules()
{
header(); box(); footer();
textcolor(9);
gotoxy(50,23); cprintf("Hit Esc return to MAIN MENU"); textcolor(4);
gotoxy(54,23); cprintf("ESC");
gotoxy(3,4); textcolor(2); cprintf("þ TOPICS "); textcolor(15);
gotoxy(3,6);  cprintf("1.Auction");
gotoxy(3,7);  cprintf("2.Bidding");
gotoxy(3,8);  cprintf("3.Franchise");
gotoxy(3,9);  cprintf("4.Squad");
gotoxy(3,10); cprintf("5.Capped Players");
gotoxy(3,11); cprintf("6.Uncapped Players");
gotoxy(3,12); cprintf("7.Retaining");       textcolor(14);
gotoxy(3,14); cprintf("Enter choice for Explanation of above terms (1-7) : ");
char choice; textcolor(14); gotoxy(54,14); cprintf("   "); gotoxy(55,14);
m: choice = getch();
if (choice==27) {menu.menu();}
else if (choice>55 || choice<49) goto m;
else {textcolor(14); cprintf("%c",choice);} gotoxy(2,16); textcolor(4);
if (choice=='1')
{cprintf("AUCTION"); gotoxy(2,17); textcolor(2);
cprintf("Process of buying players for IPL team with respect to IPL Rules.");}
else if (choice=='2')
{cprintf("BIDDING"); gotoxy(2,17); textcolor(2);
cprintf("Competing to buy player by increasing its price from base price.");}
else if (choice=='3')
{cprintf("FRANCHISE"); gotoxy(2,17); textcolor(2);
cprintf("A company (Usually a team name) who is buying players via Auction.");}
else if (choice=='4')
{cprintf("SQUAD"); gotoxy(2,17); textcolor(2);
cprintf("Entire group of players under one team."); }
else if (choice=='5')
{cprintf("CAPPED PLAYERS"); gotoxy(2,17); textcolor(2);
cprintf("Those Players who have atleast played one of any International Cricket Match.");}
else if (choice=='6')
{cprintf("UNCAPPED PLAYERS"); gotoxy(2,17); textcolor(2);
cprintf("Those Players who haven't played any International Cricket Match.");}
else if (choice=='7')
{cprintf("RETAINING"); gotoxy(2,17); textcolor(2);
cprintf("Keeping Players from previous years team so they cannot be Auctioned.");}
gotoxy(64,13); textcolor(8); cprintf("PRESS ");
textcolor(4); cprintf("Backspace");
textcolor(8); gotoxy(68,14); cprintf("TO ERASE");
b: gotoxy(56,14); choice=getch();
if(choice=='\b') {gotoxy(64,13); cout<<"               ";
				  gotoxy(68,14); cout<<"        ";
				  gotoxy(2,16); cout<<"                  "; gotoxy(2,17);
				  cout<<"                                       ";
				  cout<<"                                      ";
				  gotoxy(55,14); cout<<" ";  gotoxy(55,14); goto m;}
else if (choice==27) {menu.menu();}
else {goto b;}
}                                        //   rules() ends

void window1 :: win1menu()
{ ++ex;
  header(); footer("Use 'Space Bar' to move pointer up or down"); side();
  gotoxy(50,3); textcolor(9);
  cprintf("Select option and Press Enter");
  gotoxy(56,7); textbackground(2); textcolor(1);
  cprintf ("   CREATE NEW ACCOUNT   "); gotoxy(56,10);
  cprintf ("  LOGIN TO MY ACCOUNT   "); b0; char a=16;
  gotoxy(54,6); textcolor(4); cprintf("Hit SPACE to move UP/DOWN");
  gotoxy(54,7); textcolor (15+128); cprintf("%c",a); nil
  unsigned char updown;int n=0; m: updown = getch();
if (updown == ' ')
{  if (n%2==0) {textcolor(15);gotoxy(54,7); cprintf(" ");
				  gotoxy(54,10); cprintf("%c",a); ++n;nil goto m;}
	 else		 {textcolor(15);gotoxy(54,10); cprintf(" ");
				  gotoxy(54,7); cprintf("%c",a);  ++n;nil goto m;}
}
else if (updown==27)
{if (ex==1) {clrscr(); menu.exitapp();} else {menu.menu();}}
else if (updown==13) {if ((n%2)==0) {--ex; create_account();}
					  else {--ex; gotoxy(54,10); cprintf(" "); log_in();}}
else goto m;
}                                         // win1menu() ends

void window1::log_in()
{++ex; footer("Enter Username and Password");
gotoxy(6,5); textcolor(2); cprintf("LOG IN TO YOUR ACCOUNT");
gotoxy(6,7); textcolor(14); cprintf("Enter IPL Team Owner's Name");
gotoxy(6,8); cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(6,9); cprintf("³                          ³");
gotoxy(6,10);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"); textcolor(8);
gotoxy(6,11);cprintf("Only alphabets,digits & Underscore");
gotoxy(6,12); textcolor(14); cprintf("Enter Password");
gotoxy(6,13);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(6,14);cprintf("³                          ³");
gotoxy(6,15);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(7,9); textcolor(5); getee(obj2.uzname,26); gotoxy(7,14);
						   getee(obj2.password,16,'*'); nil
   fstream iff1 ("accipl.txt",ios::in | ios::nocreate);
   iff1.seekg(0); gotoxy(1,4);  char stp; int m=1;
while (iff1.read((char*)&obj,sizeof(obj)))
{
if(stricmp(obj.uzname,obj2.uzname)==0 && stricmp(obj.password,obj2.password)==0)
{--ex; m=0; iff1.close();  clrscr(); char chir=4; gotoxy(27,3); textcolor(14);
cprintf("%c WELCOME TO YOUR ACCOUNT %c",chir,chir);
strcpy(filename,"xxxxcp.txt");
for (int fn=0; fn<3; fn++) {filename[fn]=obj2.uzname[fn];}
rename (filename,"myteam.txt");  initialbudget=obj.budget;
menu.account_details();
}
else if(strcmp(obj.uzname,obj2.uzname)==0 && strcmp(obj.password,obj2.password)!=0)
{gotoxy(6,18); textcolor(4); cprintf("  Wrong Password !!!               ");
gotoxy(6,19); textcolor(9); cprintf(" Press any key to continue ");
nil --ex;m=0;iff1.close();stp=getch(); if(stp==27){clrscr(); menu.exitapp();}
log_in(); }
else if (strcmp(obj.uzname,obj2.uzname)!=0 && strcmp(obj.password,obj2.password)==0)
{gotoxy(6,18); textcolor(4); cprintf(" Incorrect Username !!!           ");
 gotoxy(6,19); textcolor(9); cprintf(" Press any key to continue ");
 nil  --ex; m=0; stp=getch(); iff1.close(); log_in();
 if(stp==27) {clrscr(); menu.exitapp();}
} else { m=1;} }                                   //while closed

if(m==1)
{iff1.close();
gotoxy(6,18); textcolor(4); cprintf(" Account does not Exist !!!");
gotoxy(6,19); textcolor(9); cprintf(" Press any key to continue");  nil
--ex; stp=getch();
if(stp==27) {clrscr(); menu.exitapp(); } clrscr(); win1menu();
}
}                                    // log_in() ends
void window1 :: create_account()
{ex++; clrscr(); header(); footer("Create your Account"); side();
gotoxy(30,3); textbackground(4); textcolor(0);
cprintf(" CREATE YOUR ACCOUNT "); b0
textcolor(14); gotoxy(5,6);  cprintf("      IPL Team Owner's Name : ");
textcolor(6);
gotoxy(34,5); cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(34,6); cprintf("³                          ³");
gotoxy(34,7); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(35,6); getee(obj.uzname,26);
textcolor(14); gotoxy(5,9);  cprintf("              IPL Team Name : ");
textcolor(6);
gotoxy(34,8);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(34,9);  cprintf("³                          ³");
gotoxy(34,10); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(35,9); getee(obj.team_name,26);
textcolor(14); gotoxy(5,12); cprintf("        Short Name for Team : ");
textcolor(6); gotoxy(34,11);  cprintf("ÚÄÄÄÄÄÄÄÄÄ¿");
			  gotoxy(34,12);  cprintf("³         ³");
			  gotoxy(34,13);  cprintf("ÀÄÄÄÄÄÄÄÄÄÙ");
			  gotoxy(36,12); getee(obj.abbrev,5);
textbackground(2); textcolor(1); gotoxy(2,14);
cprintf("    BUDJET in INDIAN NATIONAL CURRENCY (INR):  (Maximum - 60 Crores)          ");
b0 textcolor(2);  gotoxy(4,16);
cprintf("Rs :      CRORES,      LACS,      THOUSAND."); textcolor (4);
gotoxy(9 ,15);  cprintf("ÚÄÂÄ¿");
gotoxy(9 ,16);  cprintf("³ ³ ³");
gotoxy(9 ,17);  cprintf("ÀÄÁÄÙ");
gotoxy(22,15);  cprintf("ÚÄÂÄ¿");
gotoxy(22,16);  cprintf("³ ³ ³");
gotoxy(22,17);  cprintf("ÀÄÁÄÙ");
gotoxy(33,15);  cprintf("ÚÄÂÄ¿");
gotoxy(33,16);  cprintf("³ ³ ³");
gotoxy(33,17);  cprintf("ÀÄÁÄÙ");
for(int i=2; i<80;i++) {gotoxy(i,18); textcolor(1);cprintf("ß");}
char TC,C,TL,L,TTH,TH; long iTC,iC, iTL,iL,iTTH,iTH;
lab1: textcolor(15); gotoxy(10,16);
TC=getch(); if(isdigit(TC)) {cprintf("%c",TC);}
			else if (TC==27) {menu.menu();} else goto lab1;
lab2: gotoxy(12,16);
 C=getch(); if(isdigit(C)) {cprintf("%c",C);}
 else if (C==27) {menu.menu();}
 else if (C=='\b') {gotoxy(10,16); cprintf(" "); goto lab1;} else goto lab2;
 lab3: gotoxy(23,16);
 TL=getch(); if(isdigit(TL)) {cprintf("%c",TL);}
 else if (TL==27) {menu.menu();}
 else if (TL=='\b') {gotoxy(12,16); cprintf(" "); goto lab2;} else goto lab3;
 lab4: gotoxy(25,16);
 L=getch(); if(isdigit(L)) {cprintf("%c",L);}
 else if (L==27) {menu.menu();}
 else if (L=='\b') {gotoxy(23,16); cprintf(" "); goto lab3;} else goto lab4;
 lab5: gotoxy(34,16);
 TTH=getch(); if(isdigit(TTH)) {cprintf("%c",TTH);}
 else if (TTH==27) {menu.menu();}
 else if (TTH=='\b') {gotoxy(25,16); cprintf(" "); goto lab4;} else goto lab5;
 lab6: gotoxy(36,16);
 TH=getch(); if(isdigit(TH)) {cprintf("%c",TH);}
 else if (TH==27) {menu.menu();}
 else if (TH=='\b') {gotoxy(34,16); cprintf(" "); goto lab5;} else goto lab6;
 convert(TC,iTC); convert(C,iC); convert(TL,iTL); convert(L,iL);
 convert(TTH,iTTH); convert(TH,iTH);
 obj.budget=(iTC*100000000)+(iC*10000000)+(iTL*1000000)+(iL*100000)+(iTTH*10000)+(iTH*1000);
 gotoxy(53,15); textcolor(15); textbackground(4);
 cprintf(" BUDGET : Rs %c%c,%c%c,%c%c,000 ",TC,C,TL,L,TTH,TH); b0
 if (obj.budget>600000000)
 {gotoxy(57,16); textcolor(4+128); cprintf(" BUDGET EXCEEDS");
  gotoxy(57,17); textcolor(9); cprintf(" Re-Enter Budget");textcolor(4);
  gotoxy(10,16); cprintf(" "); gotoxy(12,16); cprintf(" ");
  gotoxy(23,16); cprintf(" "); gotoxy(25,16); cprintf(" ");
  gotoxy(34,16); cprintf(" "); gotoxy(36,16); cprintf(" "); goto lab1; }
  else
{gotoxy(57,16); cprintf("               ");
 gotoxy(57,17); cprintf("                 "); }

gotoxy(12,19); textcolor(14);
cprintf("Choose Password"); gotoxy(37,19); cprintf("RE-Enter Password");
gotoxy(10,20); cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(10,21); cprintf("³                ³");
gotoxy(10,22); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(36,20); cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(36,21); cprintf("³                ³");
gotoxy(36,22); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
char check_password[16];
p: textcolor(14); gotoxy(11,21); getee(obj.password,16,'*');
				  gotoxy(37,21); getee(check_password,16,'*');
if(strcmp(obj.password,check_password)==0)
{gotoxy(55,21);textcolor(2);cprintf("   PASSWORDS MATCH !   ");}
else
{gotoxy(55,21);textcolor(4);cprintf("PASSWORDS DOESN'T MATCH");
textcolor(14); gotoxy(11,21); cprintf("                ");
			   gotoxy(37,21); cprintf("                "); goto p; }
gotoxy(20,23); textcolor(4);  textbackground(2);
cprintf ("  CREATE ACCOUNT  "); gotoxy(47,23);
cprintf ("      RESET      "); b0 char a=16;
gotoxy(38,25); textcolor(0+128); textbackground(4);
cprintf("Use Space to move Pointer"); b0
gotoxy(18,23); textcolor (15+128); cprintf("%c",a);
unsigned char updown;int n=0; m: nil updown = getch();
if (updown == ' ')
{if (n%2==0)
{textcolor(15+128); gotoxy(18,23); cprintf(" ");
gotoxy(45,23); cprintf("%c",a); gotoxy(38,25); textbackground(4);
cprintf("                         "); ++n; b0 goto m; }
else
{textcolor(15+128); gotoxy(45,23); cprintf(" ");
gotoxy(18,23); cprintf("%c",a); ++n;nil goto m;} }
else if (updown==27) {clrscr(); menu.exitapp();}
else if (updown == 13)
{if ((n%2)==0)
{--ex; gotoxy(18,23); cprintf(" ");
fstream fillacc ("accipl.txt",ios::out | ios::nocreate | ios::app);
fillacc.write((char*)&obj,sizeof(obj));
fillacc.close(); clrscr();
gotoxy(31,3); textcolor(14+128); cprintf("ACCOUNT CREATED !!!");
strcpy(filename,"xxxxcp.txt");
for(int fn=0; fn<3; ++fn) {filename[fn]=obj.uzname[fn];}
fstream openfile ("nullfile.txt",ios::out); openfile.close();
rename("nullfile.txt","MYTEAM.txt");
fstream iff ("accipl.txt",ios::in | ios::nocreate); iff.seekg(0);
while(iff.read((char*)&obj,sizeof(obj))) {initialbudget=obj.budget;}
iff.close(); menu.account_details();
}
else {clrscr(); --ex; create_account();} } else goto m;
}                                               //create_account() ends

// FUNCTIONS OF MAIN MENU
void main_menu :: menu()
{ clrscr(); header(); box(14); footer("Select Number from Given Option ");
for (int i=3; i<25; i+=2) {textcolor (9); gotoxy(1,i); cprintf("º");
						   gotoxy(80,i); cprintf("º"); }
gotoxy(2,3);
for( i=2; i<80; ++i)
{if(i<23) {gotoxy(6,i+1); textcolor(2); cprintf("º");
						  textcolor(1); cprintf("Û"); }
gotoxy(i,3);  textcolor(1);  cprintf("Ü");
gotoxy(i,4);  textcolor(2);  cprintf("Í");}
gotoxy(6,4);                 cprintf("Î");
gotoxy(7,4);  textcolor(1);  cprintf("Û");
gotoxy(6,24); textcolor(2);  cprintf("Î"); textbackground(1);
textcolor(14); cprintf("Í"); b0
gotoxy(1,4);  textcolor(2);  cprintf("Ì");
gotoxy(80,4);                cprintf("¹");
gotoxy(7,3);  textcolor(14); textbackground(1); cprintf("Ü");
gotoxy(7,2);  textcolor(14); cprintf("Í"); b0
gotoxy(2,7);  textcolor(6);  cprintf("°°°°");
gotoxy(2,8);  textcolor(15); cprintf("°°°°");
gotoxy(2,9);  textcolor(2);  cprintf("°°°°");
gotoxy(2,19); textcolor(6);  cprintf("°°°°");
gotoxy(2,20); textcolor(15); cprintf("°°°°");
gotoxy(2,21); textcolor(2);  cprintf("°°°°");
gotoxy(4,13); textcolor(6);  cprintf("I");
gotoxy(4,14); textcolor(15); cprintf("P");
gotoxy(4,15); textcolor(2);  cprintf("L");
menu:
for (i=6; i<23; i+=2)
{ gotoxy(8,i); textcolor(4); cprintf("Í");
textcolor(15);textbackground(4); cprintf(" %i ",(i/2)-2);
textcolor(0); textbackground(2);
switch((i/2)-2)
 {case 1 : cprintf("   ACCOUNT DETAILS   "); break;
  case 2 : cprintf("   RETAIN PLAYERS    "); break;
  case 3 : cprintf(" AUCTION:BUY PLAYERS "); break;
  case 4 : cprintf(" Player's Statistics "); break;
  case 5 : cprintf(" Player Smart Search "); break;
  case 6 : cprintf("  Add Player Record  "); break;
  case 7 : cprintf("     MY IPL TEAM     "); break;
  case 8 : cprintf("     RULES / HELP    "); break;
  case 9 : cprintf("        EXIT         "); break;
 } b0 }
  gotoxy(44,5);  textcolor(15); cprintf("IPL AUCTION AUDITORIAL DESK");
  gotoxy(50,8);  textcolor(14) ; textbackground(5);
  cprintf("   MAIN MENU   "); b0
  gotoxy(44,6); textcolor(12); cprintf("Hello, %s",obj.uzname);
  gotoxy(49,22); textcolor(11); cprintf("%s",obj.team_name);
  gotoxy(49,23); textcolor(15); textbackground(4);
  cprintf(" BUDGET Rs %li ",obj.budget);  b0
  gotoxy(49,12); textcolor(4); cprintf("ENTER YOUR CHOICE");
  gotoxy(54,13);  textcolor(1); cprintf("ÉÍÍÍÍÍ»");
  gotoxy(54,14);                cprintf("º     º");
  gotoxy(54,15);                cprintf("ÈÍÍÍÍÍ¼");
  gotoxy(55,14); textcolor(15); cprintf("     ");
  textcolor(15); gotoxy(57,14); mchoice=getch();
  if (mchoice<49 || mchoice>57) {gotoxy(57,14); cprintf(" "); goto menu;}
gotoxy(57,14); cprintf("%c",mchoice);
gotoxy(52,18); textcolor(8); cprintf("PRESS"); gotoxy(53,19); cprintf("FOR");
gotoxy(58,18); textcolor(9); cprintf("ENTER");
gotoxy(65,18); textcolor(15);      cprintf("ÜÜÜÜÜ");
gotoxy(57,19); textbackground(4); cprintf(" OPTION Û %c Û",mchoice); b0
gotoxy(57,20); textcolor(9);      cprintf("ßßßßßßßß");
			   textcolor(15); cprintf("ßßßßß");
gotoxy(8,(mchoice-46)*2);   textcolor(4); cprintf("Í");
textcolor(15); textbackground(2); cprintf(" %c ",mchoice);
textcolor(14); textbackground(4);
switch(mchoice-48)
 {case 1 : cprintf("   ACCOUNT DETAILS   "); break;
  case 2 : cprintf("   RETAIN PLAYERS    "); break;
  case 3 : cprintf(" AUCTION:BUY PLAYERS "); break;
  case 4 : cprintf(" Player's Statistics "); break;
  case 5 : cprintf(" Player Smart Search "); break;
  case 6 : cprintf("  Add Player Record  "); break;
  case 7 : cprintf("     MY IPL TEAM     "); break;
  case 8 : cprintf("     RULES / HELP    "); break;
  case 9 : cprintf("        EXIT         "); break;
 } b0
textcolor(15); gotoxy(58,14); k3: key=getch();
if(key==13) {clrscr(); action();}
else if (key=='\b')
{gotoxy(57,14); cprintf(" ");	gotoxy(52,18); cprintf("                  ");
 gotoxy(53,19); cprintf("                 ");
 gotoxy(56,20); cprintf("              ");	goto menu; }
else {gotoxy(58,14); goto k3;}
}                                          // menu() closed

void main_menu :: account_details()
{ header(); box(14); footer("Details of your Account");
  gotoxy(32,5); textcolor(2); cprintf("ACCOUNT DETAILS"); textcolor(4);
  gotoxy(25,9);  cprintf("Team Owner    ");  textcolor(15); cprintf("-     ");
  textcolor(9);  cprintf("%s",obj.uzname);   textcolor(4);
  gotoxy(25,11); cprintf("IPL Team      ");  textcolor(15); cprintf("-     ");
  textcolor(9);  cprintf("%s",obj.team_name);textcolor(4);
  gotoxy(25,13); cprintf("Short form    ");  textcolor(15); cprintf("-     ");
  textcolor(9);  cprintf("%s",obj.abbrev);   textcolor(4);
  gotoxy(25,15); cprintf("Budget        ");  textcolor(15); cprintf("-     ");
  textcolor(4);  cprintf("Rs ");
  textcolor(11); textbackground(1); cprintf(" %li ",obj.budget); b0
  textcolor (15); gotoxy(50,23); cprintf("PRESS ENTER TO VIEW MAIN MENU");nil
  gotoxy(3,23); cprintf("  "); gotoxy(4,23);
  k2: key=getch(); if (key==13 || key==27) {menu();} else {goto k2;}
}                                          // menu() ends
void main_menu :: exitapp()
{if (ex==0)
 {fstream budgetchange ("tempbudget.txt", ios::out);
  fstream realbudget ("accipl.txt",ios::in | ios::nocreate);
  realbudget.seekg(0);
  while (realbudget.read((char*)&obj2,sizeof(obj2)))
  { if (strcmp(obj2.uzname,obj.uzname)==0)
	{if (obj.budget!=initialbudget)
	{budgetchange.write((char*)&obj,sizeof(obj));}
	 else {budgetchange.write((char*)&obj2,sizeof(obj2));}
	}
	else {budgetchange.write((char*)&obj2,sizeof(obj2));}
  }  budgetchange.close(); realbudget.close();
 remove("accipl.txt");
 rename("tempbudget.txt","accipl.txt");
}
 rename("MYTEAM.txt",filename); remove("MYTEAM.txt");
 header(); footer("    Designed and Developed By Hardik Panchal");
 gotoxy(1,25); textbackground(4); textcolor(15);
 cprintf("  ›++        "); textcolor(1); cprintf(""); b0
 textcolor(4);
 win1.side();
gotoxy (13,7); textcolor (6); for (int i=0; i<56; ++i) cprintf ("Ü");
for (i=8; i<16; ++i) {gotoxy(13,i); cprintf("Û"); gotoxy(68,i); cprintf("Û");}
gotoxy(14,15); for ( i=0; i<54; ++i) cprintf ("Ü"); gotoxy(22,9);
textcolor(5);  cprintf("");
textcolor(9);  cprintf(" Thank You for using this Software ");
textcolor(5);  cprintf(""); gotoxy(16,11);
textcolor(10); cprintf("\"Books are just limited to Top in the Class, ");
gotoxy(16,12); cprintf(" Practice & Determination makes you Top the World\"");
//gotoxy(43,12); textcolor(10);  cprintf("Software Engineer");
gotoxy(33,14); textcolor(14); cprintf("  HARDIK PANCHAL");
gotoxy(58,23); textcolor(8); cprintf("Press Any Key to Exit");
gotoxy(64,23); textcolor(4); cprintf("Any Key"); nil
key=getch(); exit(0);
}                                   // exitapp() ends

void main_menu :: help()
{ header(); footer(); box();
gotoxy(15,3); textcolor(14);   textbackground(5);
cprintf(" þ IMPORTANT RULES (As per IPL Regulations) :- ");
gotoxy (4,5); textcolor(2); textbackground(4); cprintf(" BUDGET "); b0
gotoxy (2,6); textcolor(15);
cprintf("¯ Minimum - 36 Crores   ¯ Maximum - 60 Crores");
gotoxy (4,8); textcolor(2); textbackground(4); cprintf(" SQUAD COMPOSITION ");b0
gotoxy (2,9); textcolor(15);
cprintf("¯ Maximum - 27 Players  ¯ Minimum - 16 Players");
gotoxy (2,10);
cprintf("À¯Maximum 9 Non-Indian Players & 4 in Playing Eleven.");
gotoxy (4,12); textcolor(2); textbackground(4);cprintf(" PLAYER RETAINING "); b0
gotoxy (2,13);textcolor(15);
cprintf("¯ Maximum 5 Players can be Retained." ); gotoxy (2,14);
cprintf("¯ Maximum 4 Indian Capped Players can be Retained.");
gotoxy (4,16);textcolor(2); textbackground(4); cprintf(" RIGHT TO MATCH ");b0
gotoxy (2,17);textcolor(15);
cprintf("¯ Once player is sold to any franchise, the auctioneer will ask other");
gotoxy (2,18);
cprintf("  franchise if they wish to excersice Right to Match.");
gotoxy (2,19);
cprintf("¯ If franchise exercise 'Right to Match', the franchise will take the");
gotoxy (2,20);
cprintf("  player for the amount of final bid made in Auction.");
gotoxy (2,21);
cprintf("¯ No further bidding by any other franchises is possible.");
gotoxy(36,23); textcolor(14);
cprintf("For Explanation of Some Terms Press E [   ]");
El: gotoxy(76,23); key=getch(); nil
if (key=='e' || key=='E') {clrscr(); win1.rules();}
else if(key==27) {menu();} else {goto El;}
}                                          // help() ends
struct player
{char  name[31];   int   age;      unsigned long base_price;
 char  nation[14]; char  type[6];  char cap[4];
 int   matches;    int   bat_inn;  long runs;
 float sr;	       float avg;
 int   s100;       int   s50;      int hs   ;
 int   bow_inn;    long  balls;    int wickets;
 char  bfig[8];    float economy;  int   wk5;
} p1,p2;
unsigned long getint (int len)
{char m[10]; unsigned long get; int y[8];
for (int i=0; i<len; ++i)
{ m: m[i]=getch();
if (i==0 && (m[i]=='\b'||m[i]==13)) {m[i]='\0'; goto m;}
else if (i==(len-1))
{if (m[i]=='\b')
{m[i]='\0'; --i; gotoxy (wherex()-1,wherey());
cprintf(" "); gotoxy (wherex()-1,wherey()); goto m; }
else if (m[i]==13) {m[i]='\0'; break;}
else if (m[i]==27) {m[i]='\0'; menu.menu();}
else {goto m;}
}
else
{if (isdigit(m[i])) {cprintf("%c",m[i]); y[i]= m[i]-48;}
else if (m[i]=='\b')
{m[i]='\0'; gotoxy (wherex()-1,wherey()); cprintf(" ");
gotoxy (wherex()-1,wherey()); --i; goto m; }
else if (m[i]==13) {m[i]='\0'; break;}
else if (m[i]==27) {m[i]='\0'; menu.menu();}
else {goto m;}
} }   //for loop

switch(i)
{ case 1 : get= y[0]; break;
   case 2 : get= y[0]*10 + y[1]; break;
   case 3 : get= y[0]*100 + y[1]*10 + y[2]; break;
   case 4 : get= y[0]*1000 + y[1]*100 + y[2]*10 +y[3]; break;
   case 5 : get= y[0]*10000 + y[1]*1000 + y[2]*100 + y[3]*10 + y[4]; break;
   case 6 : get= y[0]*100000 + y[1]*10000 + y[2]*1000 + y[3]*100 + y[4]*10 + y[5]; break;
   case 7 : get= y[0]*1000000 + y[1]*100000 + y[2]*10000 + y[3]*1000 + y[4]*100 + y[5]*10 + y[6]; break;
   case 8 : get= y[0]*10000000 + y[1]*1000000 + y[2]*100000 + y[3]*10000 + y[4]*1000 + y[5]*100 + y[6]*10 + y[7]; break;
}
if ((get%256)==13 || (get%256) ==26 ) {++get;} return get;
}                                                                  //getint

float getfloat ()
{ char m[5];  int len=5;  float dec=0,total=0;                    //float
int get=0,y[8]; int n=1;
for (int i=0; i<len; ++i)
{ m: m[i]=getch();
  if (i==0 && (m[i]=='\b'||m[i]==13)) {m[i]='\0'; goto m;}
  else if (i==(len-1))
 {if (m[i]=='\b')
  {m[i]='\0'; --i; gotoxy (wherex()-1,wherey()); cprintf(" ");   //float
		gotoxy (wherex()-1,wherey()); goto m; }
 else if (m[i]==13) {m[i]='\0'; break;}
 else if (m[i]==27) {m[i]='\0'; menu.menu();}
 else {goto m;}
 }
 else
 {if (isdigit(m[i])) {cprintf("%c",m[i]);  y[i]= m[i]-48;}
 else if (m[i]=='.') {cprintf("%c",m[i]); m[i]='\0'; n=i;        //float
					  dec = getint(3);
					  if(dec<10) {dec=dec/10;}
					  else {dec=dec/100;} break;}
 else if (m[i]=='\b')
 {m[i]='\0'; gotoxy (wherex()-1,wherey()); cprintf(" ");
  gotoxy (wherex()-1,wherey()); --i; goto m; }
 else if (m[i]==13) {m[i]='\0'; break;}
 else if (m[i]==27) {m[i]='\0'; menu.menu();}
 else {goto m;}
 } }   //for loop
 if (n==1) {n=i;}                                               //float
switch(n)
{ case 1 : get= y[0]; break;
  case 2 : get= y[0]*10 + y[1]; break;
  case 3 : get= y[0]*100 + y[1]*10 + y[2]; break;
  case 4 : get= y[0]*1000 + y[1]*100 + y[2]*10 +y[3]; break;
}
total = get+dec;
if ((get%256)==13 || (get%256)==26) {total+=0.1;}
if (total>8.8 && total<8.9) {total=8.80;}
return total;
}   //getfloat                                                 //float

void main_menu :: add_edit()
{ header(); footer(); box(); char ae =4;  int change=0;
gotoxy(24,3); textcolor(4);  textbackground(3);
cprintf(" %c ADD/EDIT PLAYER INFORMATION %c ",ae,ae); b0
textcolor(2);
gotoxy(5,4); cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(5,5); cprintf("³                                              ³");
gotoxy(5,6); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
 textcolor(4); gotoxy(7,5); cprintf("Player's Name "); gotoxy(21,5);
 textcolor(15); cprintf(":                             "); gotoxy(23,5);
 getee(p1.name,30);
 fstream iffx ("players.txt",ios::in | ios::nocreate );
 iffx.seekg(0);
 while (iffx.read((char*)&p2,sizeof(p2)))
 { if(strcmpi(p1.name,p2.name)==0)
  {change=1;
   gotoxy(54,5);  textcolor(9);  cprintf("Player Already Exist");
   gotoxy(54,6);  textcolor(12); cprintf("Edit Details? (Y/N) : ");
   gotoxy(76,6);  textcolor(12); cprintf("  ");   iffx.close();
   gotoxy(76,6);  char y; y: y = getch();
   if(y=='y'||y=='Y') { cprintf("Y"); }
   else if (y=='n'|| y=='N' || y == 27) {change=0; clrscr(); add_edit();}
   else goto y;
  }
 }  iffx.close(); //while loop closed
 gotoxy(7,8); textcolor(5);
 cprintf("Nation : ");   gotoxy(16,8); textcolor(15);
 cprintf("             "); gotoxy(16,8); getee(p1.nation,13);
 gotoxy(34,8); textcolor(3);
 cprintf("Age : ");   gotoxy(40,8); textcolor(15);
 cprintf("             "); gotoxy(40,8); p1.age=getint(3);
 gotoxy(48,8); textcolor(6);
 cprintf("Capped/Uncapped? (c/uc) : ");   gotoxy(74,8); textcolor(15);
 cprintf("     "); gotoxy(74,8); getee(p1.cap,3);
  gotoxy(7,10); textcolor(2);
 cprintf("IPL Matches Played : "); gotoxy(28,10); textcolor(15);
 cprintf("     "); gotoxy(28,10); p1.matches=getint(5);
  gotoxy(50,10); textcolor(13);
 cprintf("Bat / Bowl / Alr / Wk : ");   gotoxy(74,10); textcolor(15);
 cprintf("     "); gotoxy(74,10); getee(p1.type,5);
textcolor(14);
gotoxy(5,11);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
for (int c=12; c<22; ++c)
{gotoxy(5,c);  cprintf("³"); gotoxy(38,c); cprintf("³");}
gotoxy(5,22);  cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

gotoxy(11,12); textbackground(5); cprintf(" BATTING STATISTICS "); b0
gotoxy(10,14); textcolor(9);
 cprintf("Batting Innings : "); gotoxy(28,14); textcolor(15);
 cprintf("     "); gotoxy(28,14); p1.bat_inn=getint(5);
gotoxy(10,15); textcolor(9);
 cprintf("Runs scored     : "); gotoxy(28,15); textcolor(15);
 cprintf("      "); gotoxy(28,15); p1.runs=getint(6);
gotoxy(10,16); textcolor(9);
 cprintf("Strike Rate     : "); gotoxy(28,16); textcolor(15);
 cprintf("       "); gotoxy(28,16); p1.sr=getfloat();
gotoxy(10,17); textcolor(9);
 cprintf("    Average     : "); gotoxy(28,17); textcolor(15);
 cprintf("       "); gotoxy(28,17); p1.avg=getfloat();
gotoxy(10,18); textcolor(9);
 cprintf("    (100's)     : "); gotoxy(28,18); textcolor(15);
 cprintf("     "); gotoxy(28,18); p1.s100=getint(4);
gotoxy(10,19); textcolor(9);
 cprintf("     (50's)     : "); gotoxy(28,19); textcolor(15);
 cprintf("     "); gotoxy(28,19); p1.s50=getint(4);
gotoxy(10,20); textcolor(9);
 cprintf("Highest Score   : "); gotoxy(28,20); textcolor(15);
 cprintf("     "); gotoxy(28,20); p1.hs=getint(4);
textcolor(14);
gotoxy(43,11);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
for (c=12; c<21; ++c)
{gotoxy(43,c);  cprintf("³"); gotoxy(76,c); cprintf("³");}  //for ends
gotoxy(43,21);  cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

gotoxy(49,12); textbackground(5); cprintf(" BOWLING STATISTICS "); b0
gotoxy(48,14); textcolor(9);
 cprintf("Bowling Innings : "); gotoxy(66,14); textcolor(15);
 cprintf("     "); gotoxy(66,14); p1.bow_inn=getint(5);
gotoxy(48,15); textcolor(9);
 cprintf("Balls bowled    : "); gotoxy(66,15); textcolor(15);
 cprintf("      "); gotoxy(66,15); p1.balls=getint(6);
gotoxy(48,16); textcolor(9);
 cprintf("     Wickets    : "); gotoxy(66,16); textcolor(15);
 cprintf("    "); gotoxy(66,16); p1.wickets=getint(4);
gotoxy(48,17); textcolor(9);
 cprintf("     Economy    : "); gotoxy(66,17); textcolor(15);
 cprintf("      "); gotoxy(66,17); p1.economy=getfloat();
gotoxy(48,18); textcolor(9);
 cprintf("5 Wickets Hawl  : "); gotoxy(66,18); textcolor(15);
 cprintf("    "); gotoxy(66,18); p1.wk5=getint(3);
gotoxy(48,19); textcolor(9);
 cprintf("  Best bowling  : "); gotoxy(66,19); textcolor(15);
 cprintf("         "); gotoxy(66,19);  getee(p1.bfig,7);
gotoxy(44,22); textcolor(12);
cprintf("BASE PRICE : "); gotoxy(57,22); textcolor(15);
 cprintf("          "); gotoxy(57,22); p1.base_price=getint(9);
gotoxy(20,23); textcolor(0);  textbackground(5);
cprintf ("    ADD DETAILS   "); gotoxy(47,23);
cprintf ("      RESET      ");  char a=16; b0
gotoxy(45,25); textcolor(0+128); textbackground(4);
cprintf("Use Space to move Pointer"); b0
gotoxy(18,23); textcolor (15); cprintf("%c",a); b0 textcolor(0); gotoxy(2,3);
cprintf("  "); gotoxy(3,3);
unsigned char updown;int n=0; me: gotoxy(3,3);  updown = getch();
if (updown == ' ')                         //  1st if
{if (n%2==0)                              // 2nd if
{textcolor(15);
 gotoxy(18,23); cprintf(" "); gotoxy(45,23); cprintf("%c",a);
 gotoxy(45,25); textbackground(4); cprintf("                         ");
 ++n;b0 goto me;
}
else                                          // else 2nd iff
{textcolor(15); gotoxy(45,23); cprintf(" ");
 gotoxy(18,23); cprintf("%c",a); ++n;nil goto me;}
}
else if (updown==27) {menu();}       //else if1 1st if
else if (updown == 13)                         // else if2 1st if
{if ((n%2)==0)                                 //if else if2 1st if
{gotoxy(18,23); cprintf(" ");
fstream out ("players.txt",ios::out | ios::nocreate | ios::app);
out.write((char*)&p1,sizeof(p1));
out.close();
if (change==1)
{    int m=0;
fstream del ("players.txt", ios::in | ios::nocreate);
fstream ndel ("tempr.txt", ios::out);
del.seekg(0);
while (del.read((char*)&p2,sizeof(p2)))
{if (strcmp(p2.name,p1.name)==0 && m==0)
 {++m;//take no action
 }
 else
 {ndel.write((char*)&p2,sizeof(p2));}
} del.close(); ndel.close();
remove("players.txt");
rename("tempr.txt","players.txt");
} // if change closed

clrscr(); header(); box(); footer();
gotoxy(4,5); textcolor(4); cprintf("Processing...");
int lpcount=1; lp: for(long p=0; p<6000000; ++p);
textcolor(4);
if (lpcount<11) {gotoxy(lpcount+3,6); cprintf("þ"); nil; ++lpcount; goto lp;}
gotoxy(4,5); textcolor(2); cprintf("Processing...");
gotoxy(4,6); cprintf("þþþþþþþþþþ");  nil
for ( p=0; p<20000000; ++p);

gotoxy(4,5); textcolor(9); cprintf("DETAILS ADDED  ");
gotoxy(4,6); cprintf("            ");
gotoxy(4,7); textcolor(2); cprintf("Add Details of Another Player?");
gotoxy(4,8); textcolor(13); cprintf("YES (Press Y)");
gotoxy(4,9); textcolor(13); cprintf("NO  (Press N)"); nil
ad: key=getch();
if(key=='y'|| key=='Y') {clrscr(); add_edit();}
else if(key=='n'|| key=='N' || key==27) {menu();}
else goto ad;
}
else {clrscr(); add_edit();}
} else goto me; }                                       //add_edit() ends

void main_menu :: records()
{ header(); box(); footer(); textcolor(12);
gotoxy(7,3);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(7,4);cprintf("³                                                     ³");
gotoxy(7,5);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(9,4); textcolor(4); cprintf("Enter Player's Name : ");
textcolor(15); cprintf("                              ");
gotoxy(31,4); getee(p2.name,30);  char found = 'y';
fstream inn ("players.txt",ios::in | ios::nocreate );
inn.seekg(0);
while (inn.read ((char*)&p1,sizeof(p1)))
{  												//while open
char st1[20], st2[20];
for (int x=0; isalpha(p1.name[x]); x++) {st1[x]=p1.name[x]; }
st1[x]='\0'; ++x;  int i1=0;
for (x; x<strlen(p1.name); ++x) {st2[i1]=p1.name[x]; ++i1;}
st2[i1]='\0';
if(strcmpi(p1.name,p2.name)==0||strcmpi(st1,p2.name)==0||strcmpi(st2,p2.name)==0)
{found='y';inn.close(); break; }
else  {found='n';} }  inn.close();                               //while close
if (found=='n')
{inn.close();
 gotoxy(25,12); textcolor (12); cprintf("RECORD OF ");
				textcolor (14) ; cprintf("'%s'",p2.name);
				textcolor (12); cprintf(" NOT PRESENT ");
 textcolor(9); gotoxy(25,13); cprintf("Press 1 to Add Record");
			   gotoxy(25,14); cprintf("Press any other key to continue");
 nil min: key=getch(); if (key=='1') {clrscr(); add_edit();}
 else if (key==27) {menu();} else {clrscr(); records();}
}                                                       //if close
textcolor(15); gotoxy(31,4); cprintf("%s",p1.name);
textcolor(12); gotoxy(65,3); cprintf("BASE PRICE");
textcolor(14) ; gotoxy(65,4); cprintf("%li",p1.base_price);
textcolor(13);  gotoxy(7,7);  cprintf("Nation : ");
textcolor(15); cprintf("%s",p1.nation);  gotoxy(34,7);
textcolor(9) ; cprintf("Age : "); textcolor(15); cprintf("%i",p1.age);
textcolor(3);  gotoxy(52,7); textcolor(3); cprintf("Capped/Uncapped : ");
textcolor(15);
if(strcmp(p1.cap,"c")==0)        {cprintf("Capped");}
else if (strcmp(p1.cap,"uc")==0) {cprintf("Uncapped");}
else                             {cprintf("%s",p1.cap);}
gotoxy(7,9); textcolor(2); cprintf("IPL Matches Played : ");
			 textcolor(15); cprintf("%i",p1.matches);
gotoxy(46,9); textcolor(6); cprintf("Bat / Bowl / Alr / Wk : ");
			  textcolor(15); cprintf("%s",p1.type);
textcolor(14);
gotoxy(11,12); textbackground(5); cprintf(" BATTING STATISTICS "); b0
textcolor(14);
gotoxy(5,11);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
for (int c=12; c<22; ++c)
{gotoxy(5,c);  cprintf("³"); gotoxy(38,c); cprintf("³");}
gotoxy(5,22);  cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(9,14);
textcolor(9); cprintf("Batting Innings : ");
textcolor(15); cprintf("%i",p1.bat_inn);  gotoxy(9,15);
textcolor(9); cprintf("Runs scored     : ");
textcolor(15); cprintf("%li",p1.runs);        gotoxy(9,16);
textcolor(9); cprintf("Strike Rate     : ");
textcolor(15); cprintf("        "); gotoxy(27,16);
cout<<setprecision(2)<<p1.sr; gotoxy(9,17);
textcolor(9); cprintf("    Average     : ");
textcolor(15); cprintf("        "); gotoxy(27,17);
cout<<setprecision(2)<<p1.avg; gotoxy(9,18);
textcolor(9); cprintf("    (100's)     : ");
textcolor(15); cprintf ("%i",p1.s100); gotoxy(9,19);
textcolor(9); cprintf("     (50's)     : ");
textcolor(15); cprintf("%i",p1.s50);  gotoxy(9,20);
textcolor(9); cprintf("Highest Score   : ");
textcolor(15); cprintf("%i",p1.hs);
textcolor(14);
gotoxy(50,12); textbackground(5); cprintf(" BOWLING STATISTICS "); b0
textcolor(14);
gotoxy(43,11);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
for ( c=12; c<22; ++c)
{gotoxy(43,c);  cprintf("³"); gotoxy(76,c); cprintf("³");}  //for ends
gotoxy(43,22);  cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(48,14);
textcolor(9); cprintf("Bowling Innings : ");
textcolor(15); cprintf("%i",p1.bow_inn); gotoxy(48,15);
textcolor(9); cprintf("Balls Bowled    : ");
textcolor(15); cprintf("%li",p1.balls);    gotoxy(48,16);
textcolor(9); cprintf("     Wickets    : ");
textcolor(15); cprintf("%i",p1.wickets);  gotoxy(48,17);
textcolor(9); cprintf("     Economy    : ");
textcolor(15); cprintf("        ");       gotoxy(66,17);
cout<<setprecision(2)<<p1.economy;        gotoxy(48,18);
textcolor(9); cprintf("5 Wickets Hawl  : ");
textcolor(15); cprintf("%i",p1.wk5);      gotoxy(48,19);
textcolor(9); cprintf("  Best Bowling  : ");
textcolor(15); cprintf("%s",p1.bfig);     gotoxy(8,23);
textcolor(8); cprintf("Press ");  textcolor(4); cprintf("ENTER");
textcolor(8); cprintf(" -> Another Record ");
			  cprintf("      Press any other key ->");
textcolor(4); cprintf(" MAIN MENU");   nil
key=getch(); if(key==13) {clrscr(); records();} else {menu();}
}                                                    //records() close

struct team_formation
{ char pname[31]; char ind,cap,retained; char ptype[6];
}r1,r2;

void no_rtm (int a1, int &a2)
{if (a1==0) {a2=3;} else if(a1==1 || a1==2) {a2=2;}
else if (a1==3 || a1==4 || a1==5) {a2=1;} else {a2=0;} }

void main_menu :: retain()
{header(); box(); footer();
 int countr=0,capcount=0,rtm=5,brtm=0,n_of_players=0;
 gotoxy(32,3); textcolor(14); textbackground(5);
 cprintf(" RETAIN PLAYERS "); b0
 gotoxy(3,5); textcolor(2); cprintf("You can Retain Maximum 5 Players");
 gotoxy(3,6);               cprintf("Maximum of 4 Capped Players can be retained");
 gotoxy(3,8); textcolor(12); cprintf("For Capped Players");
 gotoxy(3,10); textcolor(9); cprintf("For 1st Player : Rs 12.5 Crores");
 gotoxy(3,11); textcolor(9); cprintf("For 2nd Player : Rs  9.5 Crores");
 gotoxy(3,12); textcolor(9); cprintf("For 3rd Player : Rs  7.5 Crores");
 gotoxy(3,13); textcolor(9); cprintf("For 4th Player : Rs  5.5 Crores");
 gotoxy(3,14); textcolor(9); cprintf("For 5th Player : Rs    4 Crores");
 gotoxy(52,8); textcolor(14); cprintf("Right To Match (RTM)");
 gotoxy(45,9); textcolor(6) ; cprintf("Players Retained  -  RTM cards");
 gotoxy(57,10); textcolor(10); cprintf("0     -     3");
 gotoxy(57,11);                cprintf("1     -     2");
 gotoxy(57,12);                cprintf("2     -     2");
 gotoxy(57,13);                cprintf("3     -     1");
 gotoxy(57,14);                cprintf("4     -     1");
 gotoxy(57,15);                cprintf("5     -     1");
 gotoxy(3,17); textcolor(12); cprintf("For Uncapped Players");
 gotoxy(3,19); textcolor(9); cprintf("For each Uncapped Player - Rs 4 Crores");
 gotoxy(53,23); textcolor(8); cprintf("Press         to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
 key=getch(); if(key==27) {menu();}
 retainback:
 clrscr(); header(); footer(); box();
 capcount=0; countr=0; rtm=5; brtm=0; n_of_players=0;
 gotoxy(32,3); textcolor(14); textbackground(5);
 cprintf(" RETAIN PLAYERS "); b0
fstream rd ("myteam.txt",ios::in | ios::nocreate);
rd.seekg(0);
while (rd.read((char*)&r1,sizeof(r1)))
{++n_of_players;
 if (r1.retained=='y') {++countr;}
 if (r1.retained=='t') {++brtm;}
 if (r1.retained=='y' && r1.cap == 'y')    {++capcount;}
}   rd.close();
no_rtm(countr,rtm); rtm-=brtm;  if (rtm<0) {rtm=0;}
gotoxy(6,5); textcolor(4); cprintf("BUDGET : Rs ");
gotoxy(18,5); textcolor(14); cprintf("%li",obj.budget);
gotoxy(53,5); textcolor(13); cprintf("Right To Match Cards : ");
gotoxy(76,5); textcolor(14);cprintf("%i",rtm);
gotoxy(53,6); textcolor(9); cprintf ("    Players Retained : ");
gotoxy(76,6); textcolor(14); cprintf("%i",countr);

if (countr==5)
{clrscr(); header(); footer(); box();
 gotoxy(32,3); textcolor(14); textbackground(5);
 cprintf(" RETAIN PLAYERS "); b0
no_rtm(countr,rtm); rtm-=brtm;
gotoxy(6,5); textcolor(4); cprintf("BUDGET : Rs ");
gotoxy(18,5); textcolor(14); cprintf("%li",obj.budget);
gotoxy(53,5); textcolor(13); cprintf("Right To Match Cards : ");
gotoxy(76,5); textcolor(14);cprintf("%i",rtm);
gotoxy(53,6); textcolor(9); cprintf ("    Players Retained : ");
gotoxy(76,6); textcolor(14); cprintf("%i",countr);
gotoxy(30,10);textcolor(2); cprintf("5 PLAYERS RETAINED");
gotoxy(24,11);textcolor(15); cprintf("NO MORE PLAYERS CAN BE RETAINED");
gotoxy(45,23);textcolor(8); cprintf("Press Enter to Return to Main Menu");
gotoxy(51,23); textcolor(4); cprintf("ENTER"); nil
here: key=getch();
if(key==13 || key==27) {menu();} else {goto here;}
}
if (n_of_players==27)
{clrscr(); header(); footer(); box();
gotoxy(32,3); textcolor(14); textbackground(5);
cprintf(" RETAIN PLAYERS "); b0
no_rtm(countr,rtm); rtm-=brtm;
gotoxy(6,5); textcolor(4); cprintf("BUDGET : Rs ");
gotoxy(18,5); textcolor(14); cprintf("%li",obj.budget);
gotoxy(53,5); textcolor(13); cprintf("Right To Match Cards : ");
gotoxy(76,5); textcolor(14);cprintf("%i",rtm);
gotoxy(53,6); textcolor(9); cprintf ("    Players Retained : ");
gotoxy(76,6); textcolor(14); cprintf("%i",countr);
gotoxy(24,10);textcolor(2); cprintf("CONGRATULATIONS !!! YOUR TEAM IS COMPLETE");
gotoxy(24,11);textcolor(15); cprintf("NO MORE PLAYERS CAN BE ADDED TO THE TEAM");
gotoxy(45,23);textcolor(8); cprintf("Press Enter to Return to Main Menu");
gotoxy(51,23); textcolor(4); cprintf("ENTER"); nil
co: key=getch(); if(key==13 || key==27) {menu();} else {goto co;}
}
gotoxy(22,8); textcolor(10); cprintf("ENTER NAME OF PLAYER TO BE RETAINED");
textcolor(12);
gotoxy(24,10); cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(24,11); cprintf("³                              ³");
gotoxy(24,12); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"); textcolor(15);
gotoxy(25,11); cprintf("                              ");
gotoxy(56,23);textcolor(8); cprintf("Press ESC -> Main Menu");
gotoxy(62,23); textcolor(4); cprintf("ESC");
gotoxy(25,11);
getee(r1.pname,30);
char player_found = 'n';
fstream toret ("players.txt",ios::in | ios::nocreate);
toret.seekg(0);
while (toret.read((char*)&p1,sizeof(p1)))
{ char st1[20], st2[20];
for (int x=0; isalpha(p1.name[x]); x++) {st1[x]=p1.name[x]; }
st1[x]='\0'; ++x;  int i1=0;
for (x; x<strlen(p1.name); ++x) {st2[i1]=p1.name[x]; ++i1;}
st2[i1]='\0';
if(strcmpi(r1.pname,p1.name)==0||strcmpi(r1.pname,st1)==0||strcmpi(r1.pname,st2)==0)
 {gotoxy(25,11); textcolor(15); cprintf("%s",p1.name);
  strcpy(r1.pname,p1.name);
  player_found='y'; break;}
  else {player_found='n';}
} toret.close();                                   // while loop ends
if (player_found=='n')
{gotoxy(24,14); textcolor(4); cprintf("Player doesn't Exist in Records");
 gotoxy(53,23); textcolor(8); cprintf("Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
 key=getch(); if(key==27) {menu();} else {goto retainback; }
}
if(strcmp(p1.cap,"c")==0) {r1.cap='y';}  else {r1.cap='n';}
if(strcmp(p1.nation,"India")==0) {r1.ind='y';} else {r1.ind='n';}
r1.retained='y';
for (int tp=0; tp<6; tp++); {r1.ptype[tp]='\0';}
strcpy(r1.ptype,p1.type);
if (capcount==4 && r1.cap=='y')
{clrscr(); header(); footer(); box();
 gotoxy(32,3); textcolor(14); textbackground(5);
 cprintf(" RETAIN PLAYERS "); b0
no_rtm(countr,rtm); rtm-=brtm; if (rtm<0) {rtm=0;}
gotoxy(6,5); textcolor(4); cprintf("BUDGET : Rs ");
gotoxy(18,5); textcolor(14); cprintf("%li",obj.budget);
gotoxy(53,5); textcolor(13); cprintf("Right To Match Cards : ");
gotoxy(76,5); textcolor(14);cprintf("%i",rtm);
gotoxy(53,6); textcolor(9); cprintf ("    Players Retained : ");
gotoxy(76,6); textcolor(14); cprintf("%i",countr);
gotoxy(30,10);textcolor(2); cprintf("4 CAPPED PLAYERS RETAINED");
gotoxy(24,11);textcolor(15); cprintf("NO MORE CAPPED PLAYERS CAN BE RETAINED");
gotoxy(53,23); textcolor(8); cprintf("Press Any Key to Continue");
gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
key=getch(); if(key==27) {menu();} else {goto retainback; }
}
fstream team ("myteam.txt",ios::in | ios::nocreate);
team.seekg(0);
while(team.read((char*)&r2,sizeof(r2)))
{ if (strcmp(r1.pname,r2.pname)==0)
 { gotoxy(24,14); textcolor(9); cprintf("PLAYER ALREADY PRESENT IN TEAM");
   gotoxy(53,23); textcolor(8); cprintf("Press Any Key to Continue");
   gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil   team.close();
   key=getch(); if(key==27) {menu();} else {goto retainback; }
 }                                                      // if close
} team.close();                                         //while close
obj2.budget = obj.budget;
unsigned long savedbudget = obj.budget;
if      (countr==0 && capcount==0 && r1.cap=='y')  {obj2.budget-=125000000;}
else if (countr==1 && capcount==1 && r1.cap=='y')  {obj2.budget-=95000000;}
else if (countr==2 && capcount==2 && r1.cap=='y')  {obj2.budget-=75000000;}
else if (countr==3 && capcount==3 && r1.cap=='y')  {obj2.budget-=55000000;}
else                                {obj2.budget-=40000000;}
gotoxy(27,13); textcolor(4); cprintf("Retain Price : ");
textcolor(15);textbackground(1); cprintf(" RS %li ",savedbudget-obj2.budget);
b0
gotoxy(25,14); textcolor(9); cprintf("PRESS ENTER TO RETAIN THIS PLAYER");
press: key=getch();
if (key==27) {clrscr(); menu();} else if (key==13) {} else {goto press;}
gotoxy(25,14); cprintf("                                  ");
if(obj2.budget>obj.budget)
{gotoxy(24,14); textcolor(3); cprintf("CANT RETAIN THIS PLAYER");
 gotoxy(24,15); textcolor(4+128); cprintf("YOU DONT HAVE SUFFICIENT BUDGET !");
 gotoxy(53,23); textcolor(8); cprintf("Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
 key=getch(); if(key==27) {menu();} else {goto retainback; }
}
else {obj.budget=obj2.budget;}
fstream team1 ("myteam.txt",ios::out | ios :: app | ios::nocreate);
team1.write((char*)&r1,sizeof(r1));
team1.close();
 gotoxy(24,14); textcolor(2); cprintf("PLAYER RETAINED");
 gotoxy(23,15); textcolor(14); cprintf("'%s'",r1.pname);
 textcolor(9); cprintf(" Retained for "); textcolor(14);
 cprintf("RS %li",savedbudget-obj2.budget);
 gotoxy(18,5); textcolor(14); cprintf("%li",obj2.budget);
 ++countr;
 no_rtm(countr,rtm); rtm-=brtm;
 gotoxy(76,5); textcolor(14);cprintf("%i",rtm);
 gotoxy(76,6); textcolor(14); cprintf("%i",countr);      --countr;
 gotoxy(53,23); textcolor(8); cprintf("Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
 char key=getch(); if(key==27) {menu();} else {goto retainback; }
}                                                   //retain() close
void clearline()
{long H=0; int m=0; H:    nil
 for (     H=0; H<30000; ++H); ++m; if(!kbhit() && m<200) {goto H;}
gotoxy(2,19); cprintf("                                                  ");
cprintf("                            ");
gotoxy(2,20); cprintf("                                                  ");
cprintf("                            ");
gotoxy(2,21); cprintf("                                                  ");
cprintf("                            ");  nil
}

void rotate()
{while (!kbhit())
{gotoxy(6,19);      textcolor(6);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(5,20);
 textbackground(4); textcolor(14); cprintf(" Û 10 THOUSAND Û "); b0
 gotoxy(6,21);      textcolor(6);   cprintf("ßßßßßßßßßßßßßßß");
 textcolor(6); gotoxy(6,20); cprintf("Û"); gotoxy(20,20); cprintf("Û"); b0
gotoxy(26,19);      textcolor(8);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(25,20);
textbackground(4);  textcolor(14); cprintf(" Û   1 LAKH   Û "); b0
gotoxy(26,21);      textcolor(8);   cprintf("ßßßßßßßßßßßßßß");
textcolor(8); gotoxy(26,20); cprintf("Û"); gotoxy(39,20); cprintf("Û"); b0
gotoxy(45,19);      textcolor(2);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(44,20);
textbackground(4);  textcolor(14); cprintf(" Û  10 LACS   Û "); b0
gotoxy(45,21);      textcolor(2);   cprintf("ßßßßßßßßßßßßßß");
textcolor(2); gotoxy(45,20); cprintf("Û"); gotoxy(58,20); cprintf("Û"); b0
gotoxy(64,19);      textcolor(1);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(63,20);
textbackground(4); textcolor(14);  cprintf(" Û  1 CRORE  Û "); b0
gotoxy(64,21);      textcolor(1);   cprintf("ßßßßßßßßßßßßß");
textcolor(1); gotoxy(64,20); cprintf("Û"); gotoxy(76,20); cprintf("Û");
clearline();
gotoxy(24,19);      textcolor(6);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(23,20);
 textbackground(4); textcolor(14); cprintf(" Û 10 THOUSAND Û "); b0
gotoxy(24,21);      textcolor(6);   cprintf("ßßßßßßßßßßßßßßß");
 textcolor(6); gotoxy(24,20); cprintf("Û"); gotoxy(38,20); cprintf("Û");
gotoxy(44,19);      textcolor(8);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(43,20);
textbackground(4);  textcolor(14); cprintf(" Û   1 LAKH   Û "); b0
gotoxy(44,21);      textcolor(8);   cprintf("ßßßßßßßßßßßßßß");
textcolor(8); gotoxy(44,20); cprintf("Û"); gotoxy(57,20); cprintf("Û");
gotoxy(63,19);      textcolor(2);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(62,20);
textbackground(4);  textcolor(14); cprintf(" Û  10 LACS   Û "); b0
gotoxy(63,21);      textcolor(2);   cprintf("ßßßßßßßßßßßßßß");
textcolor(2); gotoxy(63,20); cprintf("Û"); gotoxy(76,20); cprintf("Û");
 gotoxy(6,19);      textcolor(1);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(5,20);
textbackground(4); textcolor(14);  cprintf(" Û  1 CRORE  Û "); b0
 gotoxy(6,21);      textcolor(1);   cprintf("ßßßßßßßßßßßßß");
textcolor(1); gotoxy(6,20); cprintf("Û"); gotoxy(18,20); cprintf("Û"); b0
clearline();
gotoxy(43,19);      textcolor(6);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(42,20);
 textbackground(4); textcolor(14); cprintf(" Û 10 THOUSAND Û "); b0
gotoxy(43,21);      textcolor(6);   cprintf("ßßßßßßßßßßßßßßß");
 textcolor(6); gotoxy(43,20); cprintf("Û"); gotoxy(57,20); cprintf("Û");
gotoxy(63,19);      textcolor(8);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(62,20);
textbackground(4);  textcolor(14); cprintf(" Û   1 LAKH   Û "); b0
gotoxy(63,21);      textcolor(8);   cprintf("ßßßßßßßßßßßßßß");
textcolor(8); gotoxy(63,20); cprintf("Û"); gotoxy(76,20); cprintf("Û");
 gotoxy(6,19);      textcolor(2);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(5,20);
textbackground(4);  textcolor(14); cprintf(" Û  10 LACS   Û "); b0
 gotoxy(6,21);      textcolor(2);   cprintf("ßßßßßßßßßßßßßß");
textcolor(2); gotoxy(6,20); cprintf("Û"); gotoxy(19,20); cprintf("Û");b0
gotoxy(25,19);      textcolor(1);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(24,20);
textbackground(4); textcolor(14);  cprintf(" Û  1 CRORE  Û "); b0
gotoxy(25,21);      textcolor(1);   cprintf("ßßßßßßßßßßßßß");
textcolor(1); gotoxy(25,20); cprintf("Û"); gotoxy(37,20); cprintf("Û");
clearline();
gotoxy(62,19);      textcolor(6);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(61,20);
 textbackground(4); textcolor(14); cprintf(" Û 10 THOUSAND Û "); b0
gotoxy(62,21);      textcolor(6);   cprintf("ßßßßßßßßßßßßßßß");
 textcolor(6); gotoxy(62,20); cprintf("Û"); gotoxy(76,20); cprintf("Û");
 gotoxy(6,19);      textcolor(8);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(5,20);
textbackground(4);  textcolor(14); cprintf(" Û   1 LAKH   Û "); b0
 gotoxy(6,21);      textcolor(8);   cprintf("ßßßßßßßßßßßßßß");
textcolor(8); gotoxy(6,20); cprintf("Û"); gotoxy(19,20); cprintf("Û");
gotoxy(25,19);      textcolor(2);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(24,20);
textbackground(4);  textcolor(14); cprintf(" Û  10 LACS   Û "); b0
gotoxy(25,21);      textcolor(2);   cprintf("ßßßßßßßßßßßßßß");
textcolor(2); gotoxy(25,20); cprintf("Û"); gotoxy(38,20); cprintf("Û"); b0
gotoxy(44,19);      textcolor(1);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(43,20);
textbackground(4); textcolor(14);  cprintf(" Û  1 CRORE  Û "); b0
gotoxy(44,21);      textcolor(1);   cprintf("ßßßßßßßßßßßßß");
textcolor(1); gotoxy(44,20); cprintf("Û"); gotoxy(56,20); cprintf("Û"); b0
clearline();
}
}
void main_menu :: auction()
{ footer(); box();
int nplayers=0, nforeign=0, ncap=0, nret=0, b2rtm=0, buyrtm=0;
fstream team2 ("myteam.txt",ios::in | ios::nocreate);
while (team2.read((char*)&r1, sizeof(r1)))
{ ++nplayers; if(r1.ind=='n') {++nforeign;} if(r1.cap=='y') {++ncap;}
			  if(r1.retained =='y') {++nret;}
			  if(r1.retained =='t') {++b2rtm;}
}team2.close();
gotoxy(28,3); textcolor(14); textbackground(5);
cprintf(" AUCTION FOR THE PLAYERS "); b0
textcolor(14);
gotoxy(3,7);   cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
for (int c=8; c<13; ++c)
{gotoxy(3,c);  cprintf("³"); gotoxy(28,c); cprintf("³");}  //for ends
gotoxy(3,13);   cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(6,6); textcolor(1); textbackground(3);cprintf(" TEAM STATISTICS ");b0
gotoxy(5,8); textcolor(12);  cprintf("Total    Players : ");
			 textcolor(15);  cprintf("%i",nplayers);
			 if (nplayers<27) {gotoxy(26,8);textcolor(2); cprintf(" þ"); }
			 else             {gotoxy(26,8);textcolor(4); cprintf(" þ");
							   gotoxy(26,9);  cprintf(" þ");
							   gotoxy(26,10); cprintf(" þ");
							   gotoxy(26,11); cprintf(" þ");
							   gotoxy(26,12); cprintf(" þ");
							  }
gotoxy(5,9); textcolor(9);   cprintf("Indian   Players : ");
			 textcolor(15);  cprintf("%i",(nplayers-nforeign));
			 textcolor(2); gotoxy(26,9); cprintf(" þ");
gotoxy(5,10); textcolor(13); cprintf("Foreign  Players : ");
			 textcolor(15);  cprintf("%i",nforeign);
			 if (nforeign<9) {gotoxy(26,10); textcolor(2); cprintf(" þ"); }
			 else             {gotoxy(26,10); textcolor(4); cprintf(" þ"); }
gotoxy(5,11);textcolor(11);  cprintf("Capped   Players : ");
			 textcolor(15);  cprintf("%i",ncap);
			 textcolor(2); gotoxy(26,11); cprintf(" þ");
gotoxy(5,12);textcolor(10);  cprintf("Uncapped Players : ");
			 textcolor(15);  cprintf("%i",(nplayers-ncap));
			 textcolor(2); gotoxy(26,12); cprintf(" þ");
gotoxy(55,5); textcolor(14); cprintf("BUDGET : ");
header();
obj2.budget = obj.budget;
gotoxy(64,5); textcolor(15); textbackground(1);
cprintf(" Rs %li  ",obj2.budget); b0
gotoxy(55,6); textcolor(13); cprintf("RIGHT TO MATCH CARDS : ");
no_rtm(nret,buyrtm); buyrtm-=b2rtm;
gotoxy(78,6); textcolor(15); cprintf("%i",buyrtm);
gotoxy(34,8); textcolor(10); cprintf("    Enter Name of The Player");
gotoxy(35,9); textcolor(4);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(35,10); cprintf("³"); gotoxy(66,10); cprintf("³");
gotoxy(35,11); textcolor(4); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(36,10); textcolor(15); cprintf("                              ");
gotoxy(36,10); textcolor(15+128); cprintf("_");
gotoxy(46,23);textcolor(8); cprintf("Press ESC to return to Main Menu");
gotoxy(52,23); textcolor(4); cprintf("ESC"); nil
rotate();
if (nplayers==27)
{gotoxy(35,8); cprintf("                                    ");
 gotoxy(35,9); cprintf("                                    ");
 gotoxy(35,10); textcolor(2); cprintf("CONGRATULATIONS !!! YOUR TEAM IS COMPLETE");
 gotoxy(35,11); textcolor(15); cprintf("NO MORE PLAYERS CAN BE ADDED TO TEAM");
 gotoxy(45,23);textcolor(8); cprintf("Press Enter to Return to Main Menu");
gotoxy(51,23); textcolor(4); cprintf("ENTER");
rotate(); here3: nil key=getch();
if(key==13 || key==27) {menu();} else {goto here3;}
}                                              // if ends {nplayer}

gotoxy(6,19);      textcolor(6);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(5,20);
textbackground(4); textcolor(14); cprintf(" Û 10 THOUSAND Û "); b0
gotoxy(6,21);      textcolor(6);   cprintf("ßßßßßßßßßßßßßßß");
textcolor(6); gotoxy(6,20); cprintf("Û"); gotoxy(20,20); cprintf("Û"); b0

gotoxy(26,19);      textcolor(8);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(25,20);
textbackground(4);  textcolor(14); cprintf(" Û   1 LAKH   Û "); b0
gotoxy(26,21);      textcolor(8);   cprintf("ßßßßßßßßßßßßßß");
textcolor(8); gotoxy(26,20); cprintf("Û"); gotoxy(39,20); cprintf("Û"); b0

gotoxy(45,19);      textcolor(2);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(44,20);
textbackground(4);  textcolor(14); cprintf(" Û  10 LACS   Û "); b0
gotoxy(45,21);      textcolor(2);   cprintf("ßßßßßßßßßßßßßß");
textcolor(2); gotoxy(45,20); cprintf("Û"); gotoxy(58,20); cprintf("Û"); b0

gotoxy(64,19);      textcolor(1);   cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜ"); gotoxy(63,20);
textbackground(4); textcolor(14);  cprintf(" Û  1 CRORE  Û "); b0
gotoxy(64,21);      textcolor(1);   cprintf("ßßßßßßßßßßßßß");
textcolor(1); gotoxy(64,20); cprintf("Û"); gotoxy(76,20); cprintf("Û"); b0

gotoxy(36,10); getee(r2.pname,30);
char player_found = 'n';
fstream toret ("players.txt",ios::in | ios::nocreate);
toret.seekg(0);
while (toret.read((char*)&p1,sizeof(p1)))
{ char st1[20], st2[20];
for (int x=0; isalpha(p1.name[x]); x++) {st1[x]=p1.name[x]; }
st1[x]='\0'; ++x;  int i1=0;
for (x; x<strlen(p1.name); ++x) {st2[i1]=p1.name[x]; ++i1;}
st2[i1]='\0';
if(strcmpi(r2.pname,p1.name)==0||strcmpi(r2.pname,st1)==0||strcmpi(r2.pname,st2)==0)
 {gotoxy(36,10); textcolor(15); cprintf("%s",p1.name);
  strcpy(r2.pname,p1.name); player_found='y'; break;}
  else {player_found='n';}
} toret.close();                                   // while loop ends
if (player_found=='n')
{gotoxy(35,14); textcolor(4); cprintf("Player doesn't Exist in Records");
 gotoxy(46,23); textcolor(8); cprintf("       Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
 rotate(); key=getch(); if(key==27) {menu();} else {clrscr(); auction(); }
}                                             // if ends {player not found}
if(strcmp(p1.cap,"c")==0) {r2.cap='y';}  else {r2.cap='n';}
if(strcmp(p1.nation,"India")==0) {r2.ind='y';} else {r2.ind='n'; ++nforeign;}
r2.retained='n';
for (int tp=0; tp<6; tp++); {r2.ptype[tp]='\0';}
strcpy(r2.ptype,p1.type);
fstream team ("myteam.txt",ios::in | ios::nocreate);
team.seekg(0);
while(team.read((char*)&r1,sizeof(r1)))
{ if (strcmp(r1.pname,r2.pname)==0)
{gotoxy(35,14); textcolor(2); cprintf("PLAYER ALREADY BROUGHT AND ADDED TO TEAM");
gotoxy(46,23); textcolor(8); cprintf("       Press Any Key to Continue");
gotoxy(59,23); textcolor(4); cprintf("Any Key"); team.close();
rotate(); key=getch(); if(key==27) {menu();} else {clrscr(); auction();}
}                                                      // if close
} team.close();                                         //while close
if (nforeign>9)
{ gotoxy(35,14); textcolor(12); cprintf("No more Foreign Players can be brought");
 gotoxy(35,15); textcolor(9); cprintf("Maximum Limit Reached - 9 Foreign Players.");
 gotoxy(46,23); textcolor(8); cprintf("       Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key");
 rotate();
 key=getch(); if(key==27) {clrscr(); menu();} else {clrscr(); auction();}
}                                             // if ends {nforeign}
 gotoxy(40,12); textcolor(9); cprintf("PLAYER'S PRICE : ");
 gotoxy(58,12); textbackground(1); textcolor(15);
				cprintf("              ");
 gotoxy(58,12);	cprintf(" Rs %li ",p1.base_price); b0
 unsigned long tempbudget=obj2.budget, tempprice=p1.base_price;
 if (tempbudget<p1.base_price)
 {  gotoxy(35,14); textcolor(4); cprintf("CANT BUY THIS PLAYER ");
 gotoxy(35,15); textcolor(14); cprintf("YOU DON'T HAVE SUFFICIENT BUDGET !");
 gotoxy(46,23); textcolor(8); cprintf("       Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); nil
 rotate();
 key=getch(); if(key==27) {menu();} else {clrscr(); auction();}
 }
 else {tempbudget = tempbudget-p1.base_price;}
 gotoxy(35,13); textcolor(12); cprintf("BUDGET AFTER BUYING : ");
 gotoxy(58,13); textbackground(4); textcolor(15); cprintf("              ");
 gotoxy(58,13);	cprintf(" Rs %li ",tempbudget); b0
 textcolor(9);
 gotoxy(3,14); cprintf("Increase Price"); textcolor(2); cprintf(" PRESS '+'");
 textcolor(9);
 gotoxy(3,15); cprintf("Decrease Price"); textcolor(2); cprintf(" PRESS '-'");
 textcolor(9);
 gotoxy(3,16); cprintf("Buy Player    "); textcolor(2); cprintf(" PRESS ENTER");
 textcolor(9);
if (buyrtm!=0)
{gotoxy(3,17); cprintf("Exercise RTM "); textcolor(2); cprintf("  PRESS 'R'");}

int ptrcount=1; char ptrch=16, buy;
textcolor(15 + 128);
gotoxy(4,20); cprintf("%c",ptrch); char arrow1=26, arrow2=27;
gotoxy(3,22); textcolor(13); cprintf("Move Pointer  Forward : ");
			  textcolor(4); cprintf("PRESS %c",arrow1);
gotoxy(3,23); textcolor(13); cprintf("Move Pointer Backward : ");
			  textcolor(4); cprintf("PRESS %c",arrow2);
bk2buy: nil buy = getch();
if (ptrcount==1 && buy=='K') {goto bk2buy;}
if (ptrcount==4 && buy=='M') {goto bk2buy;}
if (buy == 'M')
 {textcolor(15);
 gotoxy(20,18); cprintf("                                               ");
 ++ptrcount; gotoxy(4,20); cprintf(" ");   gotoxy(24,20); cprintf(" ");
			  gotoxy(43,20); cprintf(" ");  gotoxy(62,20); cprintf(" ");
  if (ptrcount==1) {gotoxy(4,20); cprintf("%c",ptrch);  }
else if (ptrcount==2) {gotoxy(24,20); cprintf("%c",ptrch);  }
else if (ptrcount==3) {gotoxy(43,20); cprintf("%c",ptrch);  }
else if (ptrcount==4) {gotoxy(62,20); cprintf("%c",ptrch);  }
goto bk2buy;
 }
 else if (buy=='K')
  {textcolor(15);
  gotoxy(20,18); cprintf("                                               ");
  --ptrcount; gotoxy(4,20); cprintf(" ");   gotoxy(24,20); cprintf(" ");
			  gotoxy(43,20); cprintf(" ");  gotoxy(62,20); cprintf(" ");
  if (ptrcount==1) {gotoxy(4,20); cprintf("%c",ptrch);   }
else if (ptrcount==2) {gotoxy(24,20); cprintf("%c",ptrch);  }
else if (ptrcount==3) {gotoxy(43,20); cprintf("%c",ptrch);   }
else if (ptrcount==4) {gotoxy(62,20); cprintf("%c",ptrch);  }
goto bk2buy; }
else if (buy=='+')
{if (ptrcount==1)
{if ((tempprice +  10000)>obj2.budget)
{gotoxy(20,18); textcolor(14);
cprintf("Cant Raise Price -> Limitation of Budget"); }
else{gotoxy(20,18);cprintf("                                               ");
	 tempprice+=10000; tempbudget-=10000; }
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf("              "); gotoxy(58,13);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy;}
else if (ptrcount==2)
{if ((tempprice +  100000)>obj2.budget)
{gotoxy(20,18); textcolor(14);
cprintf("Cant Raise Price -> Limitation of Budget");}
else{gotoxy(20,18);cprintf("                                               ");
	 tempprice+=100000; tempbudget-=100000;}
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf("              "); gotoxy(58,13);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy; }
else if (ptrcount==3)
{if ((tempprice +  1000000)>obj2.budget)
{gotoxy(20,18); textcolor(14);
cprintf("Cant Raise Price -> Limitation of Budget"); }
else{gotoxy(20,18);cprintf("                                               ");
	 tempprice+=1000000; tempbudget-=1000000;
	}
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf("              "); gotoxy(58,13);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy; }
else if (ptrcount==4)
{if ((tempprice +  10000000)>obj2.budget)
{gotoxy(20,18); textcolor(14);
cprintf("Cant Raise Price -> Limitation of Budget"); }
else{gotoxy(20,18);cprintf("                                               ");
	 tempprice+=10000000; tempbudget-=10000000;}
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf("              "); gotoxy(58,13);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy;}
}
else if (buy=='-')
{  if (ptrcount==1)
	{if ((tempprice - 10000)<p1.base_price)
		{gotoxy(20,18); textcolor(14);
		cprintf("Can't Lower price -> Base price is ");
		textcolor(12); cprintf("Rs %li",p1.base_price);}
else{gotoxy(20,18);cprintf("                                               ");
tempprice-=10000; tempbudget+=10000; }
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy; }
else if (ptrcount==2)
{if ((tempprice - 100000)<p1.base_price)
{gotoxy(20,18); textcolor(14);
cprintf("Can't Lower price -> Base price is ");
textcolor(12); cprintf("Rs %li",p1.base_price); }
else{gotoxy(20,18);cprintf("                                               ");
tempprice-=100000; tempbudget+=100000;}
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy; }
else if (ptrcount==3)
{if ((tempprice - 1000000)<p1.base_price)
{gotoxy(20,18); textcolor(14);
cprintf("Can't Lower price -> Base price is ");
textcolor(12); cprintf("Rs %li",p1.base_price);}
else{gotoxy(20,18);cprintf("                                               ");
tempprice-=1000000; tempbudget+=1000000;}
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy; }
else if (ptrcount==4)
{if ((tempprice-10000000)<p1.base_price || tempprice<=10000000)
{ gotoxy(20,18); textcolor(14);
cprintf("Can't Lower price -> Base price is ");
textcolor(12); cprintf("Rs %li",p1.base_price); }
else{gotoxy(20,18);cprintf("                                               ");
tempprice-=10000000; tempbudget+=10000000;}
gotoxy(58,12); textbackground(1); textcolor(15);
cprintf(" Rs %li ",tempprice); b0
gotoxy(58,13); textbackground(4); textcolor(15);
cprintf(" Rs %li ",tempbudget); b0 goto bk2buy;}
}
else if (buy==27) {menu();}
else if ( buyrtm>0 && (buy=='r' || buy=='R'))
 {r2.retained='t'; obj2.budget=tempbudget; obj.budget=obj2.budget;
  textcolor(1); gotoxy(56,15); cprintf("(RIGHT TO MATCH Used)");}
 else if (buy==13)
 {obj2.budget=tempbudget; obj.budget=obj2.budget;}
 else {goto bk2buy;}
 fstream addteam ("myteam.txt", ios :: out | ios :: nocreate | ios :: app);
 addteam.write((char*)&r2,sizeof(r2));
 addteam.close();
 gotoxy(35,15); textcolor(2); cprintf("PLAYER ADDED TO TEAM");
 gotoxy(35,16); textcolor(14); cprintf("%s",r2.pname); textcolor(9);
 cprintf(" brought for "); textcolor(14); cprintf("Rs %li",tempprice);

 nplayers=0; nforeign=0; ncap=0; nret=0;  b2rtm=0;
fstream teaml ("myteam.txt",ios::in | ios::nocreate);
while (teaml.read((char*)&r1, sizeof(r1)))
{++nplayers;if(r1.ind=='n') {++nforeign;} if(r1.cap=='y') {++ncap;}
			if(r1.retained =='y') {++nret;} if(r1.retained =='t') {++b2rtm;}
}teaml.close();
gotoxy(24,9); textcolor(15);  cprintf("%i",(nplayers-nforeign));
gotoxy(24,10);textcolor(15);  cprintf("%i",nforeign);
			 if (nforeign<9) {gotoxy(26,8); textcolor(2); cprintf(" þ"); }
			 else             {gotoxy(26,8); textcolor(4); cprintf(" þ"); }
gotoxy(24,8); textcolor(15);  cprintf("%i",nplayers);
			  if (nplayers<27) {gotoxy(26,8); textcolor(2); cprintf(" þ"); }
			  else             {gotoxy(26,8); textcolor(4); cprintf(" þ");
								gotoxy(26,9);  cprintf(" þ");
								gotoxy(26,10); cprintf(" þ");
								gotoxy(26,11); cprintf(" þ");
								gotoxy(26,12); cprintf(" þ");
								}
gotoxy(24,11);textcolor(15);  cprintf("%i",ncap);
gotoxy(24,12);textcolor(15);  cprintf("%i",(nplayers-ncap));
gotoxy(64,5); textcolor(15); textbackground(1);
cprintf(" Rs %li  ",obj.budget);b0
no_rtm(nret,buyrtm); buyrtm-=b2rtm;
gotoxy(78,6); textcolor(15); cprintf("%i",buyrtm);  b0
 gotoxy(46,23); textcolor(8); cprintf("       Press Any Key to Continue");
 gotoxy(59,23); textcolor(4); cprintf("Any Key"); team.close();
 rotate();
 nil
 key=getch(); if(key==27) {menu();} else {clrscr(); auction(); }
 }                                             // auction() ends

void main_menu :: team()
{ header(); box(); footer();
  gotoxy(34,3); textcolor(14); textbackground(5);  cprintf(" MY IPL TEAM ");
  b0 int go=7,go2=7;
  gotoxy(4,5); textcolor(10); cprintf("PLAYERS OF %s",obj.team_name);
  fstream view ("myteam.txt", ios::in | ios::nocreate);
  while (view.read((char*)&r1,sizeof(r1)))
{ if(r1.ind=='y')
{if (go<24) {textcolor(14); gotoxy(3,go); cprintf("%s",r1.pname);
			 textcolor(14);gotoxy(33,go); cprintf("%s",r1.ptype);  ++go; }
else {textcolor(14); gotoxy(42,go2); cprintf("%s",r1.pname);
	  textcolor(14);gotoxy(72,go2); cprintf("%s",r1.ptype);  ++go2; }
}
else
{if (go<24) {textcolor(12); gotoxy(3,go); cprintf("%s",r1.pname);
			 textcolor(12);gotoxy(33,go); cprintf("%s",r1.ptype);  ++go; }
else {textcolor(12); gotoxy(42,go2); cprintf("%s",r1.pname);
	  textcolor(12);gotoxy(72,go2); cprintf("%s",r1.ptype);  ++go2; }
}
}   view.close();
gotoxy(58,19); textcolor(15);  cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(58,20); cprintf("³"); gotoxy(78,20); cprintf("³");
gotoxy(58,21); cprintf("³"); gotoxy(78,21); cprintf("³");
gotoxy(58,22); textcolor(15); cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
gotoxy(60,20); textcolor(14); cprintf("þ Indian  Players");
gotoxy(60,21); textcolor(12); cprintf("þ Foreign Players");
gotoxy(45,23);textcolor(8); cprintf("Press Enter to Return to Main Menu");
gotoxy(51,23); textcolor(4); cprintf("ENTER"); nil
retrn: gotoxy(2,3); cprintf(" "); gotoxy(2,3);
key=getch();
if(key==13 || key==27) {menu();} else {goto retrn;} }

void main_menu :: smart()
{ header(); footer(); box(); int yco=5;
  gotoxy(33,3); textcolor(14); textbackground(5); cprintf(" SMART SEARCH ");
  b0 textcolor (10);
  gotoxy(7,5); cprintf("Search a Player by :-");
  textcolor(14); gotoxy(7,7);  cprintf("1. Nation");
  textcolor(5) ; gotoxy(7,8);  cprintf("2. Bat/Bowl/Alr/Wk");
  textcolor(3) ; gotoxy(7,9); cprintf("3. Capped / Uncapped");
  textcolor(9);  gotoxy(7,10); cprintf("4. Runs Scored ");
  textcolor(12); gotoxy(7,11); cprintf("5. Batting Average ");
  textcolor(15); gotoxy(7,12); cprintf("6. Strike Rate");
  textcolor(11); gotoxy(7,13); cprintf("7. Wickets");
  textcolor(13); gotoxy(7,14); cprintf("8. Economy ");
  textcolor(6) ; gotoxy(7,15); cprintf("9. Base Price");
  textcolor(2); gotoxy(7,17); cprintf("Select from the given Options : ");
  fstream search ("players.txt", ios::in | ios::nocreate);
  gotoxy(39,17); textcolor(14); cprintf(" "); gotoxy(39,17); char opt;
  opt: opt=getch();
  if (opt=='1')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter the Nation : ");
  textcolor(15); cprintf("                  ");
  gotoxy(26,18); getee(p1.nation,13);
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("NATION");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (strcmpi(p1.nation,p2.nation)==0)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("%s",p2.nation); ++yco; }
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players");  nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("NATION");
		yco=5;
		}
  }
  }                                              //while ends

}
else if (opt=='2')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Bat / Bowl / Alr / Wk : ");
  textcolor(15); cprintf("                  ");
  gotoxy(31,18); getee(p1.type,5);
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("TYPE");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (strcmpi(p1.type,p2.type)==0)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("%s",p2.type); ++yco; }
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players"); nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("TYPE");
		yco=5;
		}
  }
  }                                              //while ends

}
else if (opt=='3')
{  cprintf("%c",opt); gotoxy(7,18); cprintf("Capped/Uncapped (c/uc) : ");
  textcolor(15); cprintf("                  ");
  gotoxy(32,18); getee(p1.cap,3);
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("CAP");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (strcmpi(p1.cap,p2.cap)==0)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("%s",p2.cap); ++yco; }
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players"); nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("CAP");
		yco=5;
		}
  }
  }                                              //while ends

}
else if (opt=='4')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter Minimum Runs : ");
  textcolor(15); cprintf("                  ");
  gotoxy(28,18); p1.runs=getint(6);
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("RUNS");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (p2.runs>=p1.runs)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("%li",p2.runs); ++yco; }
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players");  nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("RUNS");
		yco=5;
		}
  }
  }                                              //while ends
}
else if (opt=='5')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter Minimum Average : ");
  textcolor(15); cprintf("                  ");
  gotoxy(31,18); p1.avg=getfloat();
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("AVERAGE");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (p2.avg>=p1.avg)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("       ");
				 gotoxy(40,yco); cout<<setprecision(2)<<p2.avg; ++yco;}
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players"); nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("AVERAGE");
		yco=5;
		}
  }
  }                                              //while ends
}
else if (opt=='6')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter Minimum Strike Rate : ");
  textcolor(15); cprintf("                  ");
  gotoxy(35,18); p1.sr=getfloat();
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("STRIKE RATE");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (p2.sr>=p1.sr)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("       ");
				 gotoxy(40,yco); cout<<setprecision(2)<<p2.sr; ++yco;}
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players");  nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("STRIKE RATE");
		yco=5;
		}
  }
  }                                              //while ends
}
else if (opt=='7')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter Minimum Wickets : ");
  textcolor(15); cprintf("                  ");
  gotoxy(31,18); p1.wickets=getint(4);
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("WICKETS");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (p2.wickets>=p1.wickets)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("%i",p2.wickets); ++yco; }
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players"); nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("WICKETS");
		yco=5;
		}
  }
  }                                              //while ends
}
else if (opt=='8')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter Maximum Economy : ");
  textcolor(15); cprintf("                  ");
  gotoxy(31,18); p1.economy=getfloat();
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("ECONOMY");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (p2.economy<=p1.economy && p2.economy!=0)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("       ");
				 gotoxy(40,yco); cout<<setprecision(2)<<p2.economy; ++yco;}
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players"); nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("ECONOMY");
		yco=5;
		}
  }
  }                                              //while ends
}
else if (opt=='9')
{ cprintf("%c",opt); gotoxy(7,18); cprintf("Enter Maximum Base Price : ");
  textcolor(15); cprintf("                  ");
  gotoxy(34,18); p1.base_price=getint(9);
  clrscr(); header(); footer(); box();
  textcolor(10); gotoxy(10,3); cprintf("NAME");
  gotoxy(40,3); cprintf("BASE PRICE");
  gotoxy(6,5); textcolor(1); cprintf("EMPTY !");
  search.seekg(0);
  while (search.read((char*)&p2,sizeof(p2)))
  { if (p2.base_price<=p1.base_price)
  {if (yco<22)
  {textcolor(14); gotoxy(6,yco); cprintf("%s",p2.name);
  textcolor(12); gotoxy(40,yco); cprintf("%li",p2.base_price); ++yco; }
  else {gotoxy(10,23); textcolor(9);
		cprintf("Press Any key to View More Players");  nil
		key = getch(); if(key==27) {menu();}
		clrscr(); header(); footer(); box();
		textcolor(10); gotoxy(10,3); cprintf("NAME");
		gotoxy(40,3); cprintf("BASE PRICE");
		yco=5;
		}
  }
  }                                              //while ends
}
else if (opt==27)   {menu();}
else {goto opt;}    search.close();
gotoxy(52,23); textcolor(9); cprintf("Press ENTER -> Smart Search");
gotoxy(58,23); textcolor(4); cprintf("ENTER");
kn: nil
key = getch();
if (key == 13) {clrscr(); smart();}
else if (key == 27) {menu();}
else {goto kn;}
}

void main_menu :: action()
{ switch(mchoice)
{ case '1' : clrscr(); account_details();  break;
  case '2' : clrscr(); retain();           break;
  case '3' : clrscr(); auction();          break;
  case '4' : clrscr(); records();          break;
  case '5' : clrscr(); smart();            break;
  case '6' : clrscr(); add_edit();         break;
  case '7' : clrscr(); team();             break;
  case '8' : clrscr(); help(); 			   break;
  case '9' : clrscr(); exitapp();          break;
  default  : exit(0);
}
}
void main()
{clrscr();
welcome();
char key; k1:  key=getch();
if (key==13)
{gotoxy(34,15); textcolor(4); cprintf("Loading..."); nil
int lpcount=1; lp:
for(long p=0; p<2000000; ++p);
if (lpcount<11)
{gotoxy(lpcount+33,16); textcolor(4); cprintf("þ"); nil ++lpcount; goto lp;}
gotoxy(34,15); textcolor(2); cprintf("Loading...");
gotoxy(34,16);               cprintf("þþþþþþþþþþ"); nil
for (p=0; p<6000000; ++p);
clrscr(); win1.win1menu();
}
else if (key==27) {clrscr(); menu.exitapp();}
else goto k1;
getch();
}