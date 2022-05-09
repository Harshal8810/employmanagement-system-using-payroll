#include<iostream>
#include<windows.h>
#include<conio.h>
#include<mysql.h>
#include<sstream>
#include<stdlib.h>
#include<string>


using namespace std;


const char* hostname = "localhost";
const char* username = "root";
const char* password = "";
const char* database = "hiprimed";
unsigned int port = 3306 ;
const char* unixsocket =NULL ;
unsigned long clientflag = 0;

MYSQL* connectdatabase()
{
    MYSQL*conn;
    conn= mysql_init(0);
    conn= mysql_real_connect(conn,hostname,username,password,database,port,unixsocket,clientflag);
    if(conn){
        cout<<" HEY USER CONNECTED TO DATABASE"<<endl;
        return conn;
    }
    else{
        cout<<" OOOOOPS    FAILED TO CONNECT TO DATABASE"<<endl;
        return conn;
    }




}



insert(MYSQL*conn)
{


    int qstate=0;
    stringstream ss;




	string name,code,des,exp,sal,loan,location,contact,basic,hra ,bonus ;

	cout << "\n\n\t\t\t INSERT RECORD";

	cout << "\n EMPLOYEE NAME : ";
	cin >> name;
	cout << "\n EMPLOYEE CODE : ";
	cin >> code;
    cout<<"\n DESIGNATION  : ";
    cin>>des;
    cout<<"\nEXPERIENCE IN YEARS :  ";
    cin>>exp;
    cout<<"\n SALARY :  ";
    cin>>sal;
    cout<<"\n LOAN :   ";
    cin>>loan;
    cout<<"\n LOCATION : ";
    cin>>location;
    cout<<"\n  CONTACT NO  :  ";
    cin>>contact;

    cout<<"\n  ENTER HRA  :  ";
    cin>>hra;

    cout<<"\n  ENTER BASIC SALARY  :  ";
    cin>>basic;
    cout<<"\n  ENTER BONUS   :  ";
    cin>>bonus;



    ss <<  "INSERT INTO hproject (NAME, CODE,DESIGNATION,EXPERIENCE,SALARY,LOAN,LOCATION,CONTACT,HRA,BASIC,BONUS )VALUES('"+name+"','"+code+"','"+des+"','"+exp+"','"+sal+"','"+loan+"','"+location+"','"+contact+"','"+hra+"','"+basic+"','"+bonus+"' )";
    string query = ss.str();
    const char* q= query.c_str();
    qstate = mysql_query(conn,q);
    if(qstate==0){
        cout<<"RECORD INSERTED......\n";

    }
else {
    cout<<"FAILED TO INSERT ........\n";
}


}

display(MYSQL*conn)
{
    MYSQL_ROW row;
    MYSQL_RES *res;
    if(conn)
    {
        int qstate = mysql_query(conn,"SELECT * FROM hproject");


    if (!qstate)
    {
        res= mysql_store_result(conn);
        int count = mysql_num_fields(res);

    cout<<"\tNAME  CODE  DESIGNATION EXPERIENCE SALARY LOAN LOCATION  CONTACT      HRA    BASIC    BONUS";
    cout<<endl;
    cout<<endl;
        while(row=mysql_fetch_row(res))
        {
            for(int i=0;i<count;i++)
            {
                cout<<"\t"<<row[i];
            }
            cout<<endl;


        }
    }


    }
    else{
        cout<<"FAILED TO FETCH";
    }


    Sleep(3000);




}


 deleteemployee(MYSQL*conn)

 {
 MYSQL_ROW row;
 MYSQL_RES* res;
 string  codes;

 cout<<" ENTER THE EMPLOY ID TO DELETE  ";

 cin>>codes;
 stringstream ss,sss;

 sss<< "SELECT * FROM hproject where CODE='"+codes+"'";
 string query = sss.str();
 const char *q = query.c_str();
 mysql_query(conn,q);
 res = mysql_store_result(conn);
 int count = mysql_num_fields(res);
 my_ulonglong x= mysql_num_rows(res);
 if(x>0)
    {
    ss<< "DELETE FROM hproject WHERE CODE ='"+codes+"'";
    string query= ss.str();
    const char *q = query.c_str();
    mysql_query(conn,q);
    cout<<"RECORD FOUND\n\n\n DELETED SUCCESSFULLY";
 }
 else {
    cout<<"NO RECORD FOUND ";
 }

 }



payrolldisplay(MYSQL*conn)
{
    MYSQL_ROW row;
    MYSQL_RES *res;
    if(conn)
    {
        int qstate = mysql_query(conn,"SELECT CODE,NAME,DESIGNATION,SALARY ,LOCATION,CONTACT   FROM hproject");


    if (!qstate)
    {
        res= mysql_store_result(conn);
        int count = mysql_num_fields(res);
        cout<<"\n\n\n\t\tCODE  \t\tNAME \t\t DESIGNATION  \tSALARY \t   LOCATION \t\tCONTACT     ";
        cout<<endl;
        while(row=mysql_fetch_row(res))
        {
            for(int i=0;i<count;i++)
            {
                cout<<"\t\t"<<row[i];
            }
            cout<<endl;


        }
    }


    }
    else{
        cout<<"FAILED TO FETCH ";
    }





}




modify(MYSQL*conn)
{
string news;
string dbt;
string csd;




        int x;
        int experiences ,salarys;
    if(conn)


    {
        int qstate = 0;
        string name;
        cout << "ENTER THE EMPLOY CODE TO MODIFY  :  ";
        cin>>name;




         cout<<"PRESS... 1 FOR EXPERIENCE "<<endl;
         cout<<"PRESS... 2 FOR SALARY   "<<endl;
         cout<<"PRESS ... 3 FOR DESIGNATION CHANGE "<<endl;
         cout<<"PRESS ... 4 FOR NAME  CHANGE "<<endl;




         cout<<"   ENTER YOUR CHOICE   "<<" ";
         cin>>x;

         if(x==1)
         {

             cout<<"ENTER NEW EXPERIENCE IN YEARS "<<" ";
             cin>>experiences;




                   stringstream ss;
                      ss << "UPDATE hproject SET EXPERIENCE =  " << experiences   << " WHERE CODE = '" << name << "'";


                  string query = ss.str();

                   const char* q = query.c_str();
                   qstate = mysql_query(conn, q);
                   if(qstate == 0){
                   cout << "\n\nRECORD UPDATED..." << endl;
                   }
                   else{
                       cout<<"\n\nRECORD NOT UPDATED";
                   }

        }







         else if(x==2)
            {


             cout<<"ENTER NEW SALARY "<<" ";
             cin>>salarys;




                   stringstream ss;
                      ss << "UPDATE hproject SET SALARY =  " << salarys << " WHERE CODE = '" << name << "'";

                  string query = ss.str();

                   const char* q = query.c_str();
                   qstate = mysql_query(conn, q);
                   if(qstate == 0){
                   cout << "\n\nRECORD UPDATED..." << endl;
                   }
                   else{
                       cout<<"\n\nRECORD NOT UPDATED";
                   }



         }


         else if(x==3)
         {

             cout<<"ENTER NEW DESIGNATION   "<<" ";
             cin>>news;




                   stringstream ss;

                      ss<< "UPDATE hproject  SET DESIGNATION ='" + news + "' WHERE CODE = '"<<name<<"'";

                  string query = ss.str();

                   const char* q = query.c_str();
                   qstate = mysql_query(conn, q);
                   if(qstate == 0){
                   cout << "\n\nRECORD UPDATED..." << endl;
                   }
                   else{
                       cout<<"\n\nRECORD NOT UPDATED";
                   }

        }



         else if(x==4)
         {

             cout<<"ENTER NEW NAME ";
             cin>>dbt;
            stringstream ss;

                      ss<< "UPDATE hproject  SET NAME ='" + dbt + "' WHERE CODE = '"<<name<<"'";

                  string query = ss.str();

                   const char* q = query.c_str();
                   qstate = mysql_query(conn, q);
                   if(qstate == 0){
                   cout << "\n\nRECORD UPDATED..." << endl;
                   }
                   else{
                       cout<<"\n\nRECORD NOT UPDATED";
                   }

         }




         else {
            cout<<"WRONG CHOICE ";
         }

    }







}



truncatee(MYSQL*conn)
{

 MYSQL_ROW row;
 MYSQL_RES* res;

 stringstream ss,sss;

 sss<< "SELECT * FROM hproject ";
 string query = sss.str();
 const char *q = query.c_str();
 mysql_query(conn,q);
 res = mysql_store_result(conn);
 int count = mysql_num_fields(res);
 my_ulonglong x= mysql_num_rows(res);
 if(x>0)
    {

    ss<< "DELETE FROM hproject";
    string query= ss.str();
    const char *q = query.c_str();
    mysql_query(conn,q);
    cout<<"\n\n\n DELETED SUCCESSFULLY";

    }
 else {
    cout<<"NO RECORD FOUND ";
 }

 }





  int main()
   {
       int s;
   MYSQL*conn= connectdatabase();

	cout << "\n\n\t\tEMPLOYEE MANAGEMENT USING PAYROLL" << endl;
	string username, password;

	cout << "\n\n\n\n\t\t    SIGN UP  FOR ADMIN    " << endl;

	cout << "\n\n\t\t ENTER NEW USERNAME : ";
	cin >> username;

	cout << "\n\n\t\t ENTER NEW PASSWORD : ";
	cin >> password;
	cout << "\n\n\n\n\n\t\tYOUR NEW ID IS CREATING ";

	for (int i = 0; i < 6; i++)
	{
		cout << ".";
		Sleep(500);
	}
	cout << "\n\n\n\t\tYOUR ID CREATED SUCCESSFULLY";
	Sleep(2000);


	system("CLS");

	string usrn, pswd;
	int p;

	op:

	cout<<"\n\n\t\t ...............CONTROL PANEL..............";
	cout<<"\n\n\n\t\t\t\t CHOOSE YOUR CHOICE ";
	cout<<"\n\n\t\t 1.  EMPLOY MANAGEMENT";
	cout<<"\n\n\t\t 2. PAYROLL SLIP DISPLAY ";
	cout<<"\n\n\t\t 3. EXIT";
	cout<<endl;
	cout<<"\n\n\t\t ENTER YOUR CHOICE   ";

	cin>>s;
	if(s==3){
        exit(0);
	}


	if(s==2)
	{
            system("CLS");
            cout << "\n\n\t\t   PAYROLL ADMINSTRATION    LOGIN       " << endl;
            cout<<endl;
	cout << "\n\n\n\n\t\t\tENTER USERNAME: ";
	cin >> usrn;
	cout<<endl;
	cout << "\t\t\n\n\t\t\t ENTER PASSWORD : ";
	cin >> pswd;



	    if (usrn == username && pswd == password)
	    {
		system("CLS");

		payrolldisplay(conn);

		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;





		 cout<<"\t\t\t ENTER 1 FOR PREVIOUS MENU      ";

		cin>>p;

   if(p==1){
		goto op;
   }


	    }
	}




else{
        system("CLS");

	cout << "\n\n\t\tEMPLOYEE MANAGEMENT SYSTEM" << endl;
	cout << "\n\n\n\t\t   LOGIN" << endl;
	cout << "\n\n\n\t\tENTER USERNAME: ";
	cin >> usrn;
	cout << "\n\n\n\t\tENTER PASSWORD: ";
	cin >> pswd;



	if (usrn == username && pswd == password)
	{
		system("CLS");
		int x;

		while (1) {

             cout<<"\n\n\n\t\t\t\t CONTROL PANEL";
              cout<<"\n\n  1.  INSERT RECORD";
              cout<<"\n\n  2.   DISPLAY RECORD ";
              cout<<"\n\n  3. MODIFY RECORD ";
              cout<<"\n\n  4. DELETE RECORD";
              cout<<"\n\n  5. TRUNCATE ALL RECORD";
               cout<<"\n\n 6. BACK TO MAIN  MENU";
               cout<<"\n\n 7. EXIT ";
               cout<<"\n\n PLEASE ENTER YOUR CHOICE    ";

               cin>>x;



			system("CLS");
			switch(x)
             {
			case 1:insert(conn);
					break;


			case 2: display(conn);
					break;

			case 3: modify(conn);
				 break;

            case 4:deleteemployee(conn);
				 break;
            case 5: truncatee(conn);
                  break;
			case 6:goto op;
			break;
			case 7 : exit(0);
			break;


			default:cout << "\aInvalid Input" << endl;
			return (0);

			}
		}
	}
	else if (usrn != username)
	{
		cout << "\t\t\aInvalid username please try again";
		Sleep(2000);
		goto op;
	}
	else if (pswd != password)
	{
		cout << "\t\t\aInvalid password please try again";
		Sleep(3000);
		goto op;
	}
	else {
		cout << "\t\t\aInvalid username and password";
		Sleep(3000);
		goto op;
	}



}
	return 0;
   }


