#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
class Person
{
public:
    string name;
    int age;
    long long phoneno;
    string district;
	string plasma;
    Person()
    {
        name = "";
        age = 0;
        phoneno = 0;
        district = "";
    }
    void display()
    {
        cout << "Patient name: " << name << endl;
        cout << "Patient age: " << age << endl;
        cout << "Patient phoneno: " << phoneno << endl;
        cout << "Patient district: " << district << endl;
        cout << endl;
    }
     void displayofdonor()
    {
    	cout<<" Donor name:" <<name<<endl;
    	cout<<" Donor age:" <<age<<endl;
    	cout<<" Donor phoneno:" <<phoneno<<endl;
    	cout<<" Donor district: "<<district <<endl;
		cout<<" Donor plasma: "<<plasma <<endl;
	}
    
};
class patient : public Person{
public:
int pid;
int days;
string intensiveCareNeeded;
string rt_pcr;
string hasMedicalInsurance;
patient()
    {
        pid=0;
        days=0;
        intensiveCareNeeded="";
        rt_pcr="";
        hasMedicalInsurance="";
    }
};
bool operator<(const Person &a, const Person &b)
{
    int i = 0;
    while (i < a.name.size() && i < b.name.size())
    {
        if (a.name[i] != b.name[i])
        {
            return a.name[i] > b.name[i];
        }
        i++;
    }
    if (i == a.name.size())
    {
        return false;
    }
    else if (i == b.name.size())
    {
        return true;
    }
}
void searchbyname(string name)
{
    ifstream f;
    f.open("Covid Data.txt");
    int pf = 0; //Number of persons by same name
    while (true)
    {
        if (f.eof() != 0)  // if eof is reached it return a non-zero value when end of file reached
        {
            if (pf == 0)
            {
                cout << "Not Found" << endl;
            }
            break;
        }
        char str[100];
        f.getline(str, 100);
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;  
                i++;  //work for characters after space as below for check conditions are checked  ,
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');
            }
            else
            {
                p.district += str[i];
            }
            i++;
        }
        if (p.name == name)
        {
            pf++;
            p.display();
        }
    }
}
void searchbyphoneno(long long phoneno)
{
    ifstream f;
    f.open("Covid Data.txt");
    while (true)
    {
        if (f.eof() != 0)
        {
            cout << "Not Found" << endl;
            break;
        }
        char str[100];
        f.getline(str, 100);
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;
                i++;
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');
            }
            else
            {
                p.district += str[i];
            }
            i++;
        }
        if (p.phoneno == phoneno)
        {
            p.display();
            break;
        }
    }
    f.close();
}
int TotalPatients()
{
    ifstream f;
    f.open("Covid Data.txt");
    int count = -1;
    while (f.eof() == 0)
    {
        char str[100];
        f.getline(str, 100);
        count++;
    }
    f.close();
    return count;
}
int PatientsInDistrict(string district)
{
    ifstream f;
    f.open("Covid Data.txt");
    int count = 0;
    while (true)
    {
        if (f.eof() != 0)
        {
            break;
        }
        char str[100];
        f.getline(str, 100);
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;
                i++;
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');
            }
            else
            {
                p.district += str[i];
            }
            i++;
        }
        if (p.district == district)
        {
            count++;
        }
    }
    f.close();
    return count;
}
void zone_distribution(string district)
{
    if(PatientsInDistrict(district)>=5)
    {
        cout<<"District "<<district<<" is in Red Zone";
    }
    else if(PatientsInDistrict(district)<5 && PatientsInDistrict(district)>0)
    {
        cout<<"District "<<district<<" is in Orange Zone"; 
    }
    else if(PatientsInDistrict(district)==0)
    {
        cout<<"District "<<district<<" is in Green Zone";
    }
    cout<<endl;
}
void displayAll()
{
    ifstream f;
    f.open("Covid Data.txt");
    priority_queue<Person> pq;
    while (true)
    {
        if (f.eof() != 0)
        {
            break;
        }
        char str[100];
        f.getline(str, 100);
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;
                i++;
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');
            }
            else
            {
                p.district += str[i];
            }
            i++;
        }
        if (p.phoneno == 0)
        {
            break;
        }
        pq.push(p);
    }
    f.close();
    cout << "Name"
         << "\t"
         << "Age"
         << "\t"
         << "Phoneno"
         << "\t\t"
         << "District" << endl;
    while (pq.size() > 0)
    {
        Person top = pq.top();
        cout << top.name << "\t" << top.age << "\t" << top.phoneno << "\t" << top.district << endl;
        pq.pop();
    }
    cout << endl;
}
Person DeleteRecord(string name)
{
    Person rv;
    fstream f;
    fstream temp;
    f.open("Covid Data.txt", ios::in);
    temp.open("temp.txt", ios::out);
    while (true)
    {
        if (f.eof() != 0)
        {
            break;
        }
        char str[100];
        f.getline(str, 100);
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;
                i++;
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');
            }
            else
            {
                p.district += str[i];
            }
            i++;
        }
        if (p.phoneno == 0)
        {
            break;
        }
        else if (p.name != name)
        {
            temp << p.name << " " << p.age << " " << p.phoneno << " " << p.district << endl;
        }
        else if (p.name == name)
        {
            rv = p;
        }
    }
    temp.close();
    f.close();
    remove("Covid Data.txt");
    rename("temp.txt", "Covid Data.txt");
    return rv;
}
void searchbyplasma(string plasma)
{
	ifstream f;
	f.open("Donor Data.txt");
	int pf=0;
	while(true)
	{
	 	 if(f.eof()!=0)
	 	 {
	 	 	if(pf==0)
	 	 	{
	 	 		cout<<"Donor of this blood group not available "<<endl;
			  }
			  break;
		  }
		   char str[100];
        f.getline(str, 100);           
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')                 // riya   23   7685432198   gurugram 
            {
                check++;                     
                i++;
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');          //0*10+ 2-'0'=0+2=2           //2*10+(3-0)=23 
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');       // 
            }
            else if(check==3)
            {
                p.district += str[i];
            }
            else
            {
            	p.plasma+=str[i];
			}
            i++;
        }
        if (p.plasma == plasma)
        {
            pf++;
            p.displayofdonor();
        }
    }
    f.close();
	}
int SameDonor(string plasma)
{
    ifstream f;
    f.open("Donor Data.txt");
    int count = 0;
    while (true)
    {
        if (f.eof() != 0)
        {
            break;
        }
        char str[100];
        f.getline(str, 100);
        Person p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;
                i++;
            }
            if (check == 0)
            {
                p.name += str[i];
            }
            else if (check == 1)
            {
                p.age = p.age * 10 + (str[i] - '0');
            }
            else if (check == 2)
            {
                p.phoneno = p.phoneno * 10 + (str[i] - '0');
            }
            else if(check==3)
            {
                p.district += str[i];
            }
            else
            {
            	p.plasma+=str[i];
			}
            i++;
        }
        if (p.plasma== plasma)
        {
            count++;
        }
    }
    f.close();
    return count;
}
void generatebill(int pid)
{
    ifstream fp;
    fp.open("patientRecord.txt");
    while (true)
    {
        if (fp.eof())
        {
            cout << "Wrong patient id" << endl;
            break;
        }
        char str[100];
        fp.getline(str, 100);
        patient p;
        int i = 0, check = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                check++;
                i++;
            }
            if (check == 0)
            {
                p.pid = p.pid * 10 + (str[i] - '0');
            }
            else if (check == 1)
            {
                p.name += str[i];
            }
            else if (check == 2)
            {
                p.days = p.days * 10 + (str[i] - '0');
            }
            else if (check == 3)
            {
                p.intensiveCareNeeded += str[i];
            }
            else if (check == 4)
            {
                p.rt_pcr += str[i];
            }
            else if (check == 5)
            {
                p.hasMedicalInsurance += str[i];
            }
            i++;
        }
        if (p.pid == pid)
        {
            int total = 0;
            cout<<"*******************************************************************************************"<<endl;
            cout << "                      HOSPITAL BILL OF " << p.name << endl;
            cout << endl;
            if (p.rt_pcr == "yes")
            {
                cout << "Cost of rt pcr test " << (800) << endl;
                cout << endl;
                total += 800;
            }
            if (p.intensiveCareNeeded == "yes")
            {
                cout << "Total Cost of bed for "<< p.days<<" days is "<< (p.days * 3000) << endl;
                cout << endl;
                total += (p.days * 3000);
            }
            else
            {
                cout << "Total Cost of bed for "<<p.days<<" days is " << (p.days * 2000) << endl;
                cout << endl;
                total += (p.days * 1500);
            }
            if (p.hasMedicalInsurance == "yes")
            {
                cout << "Contact your Third Party Administrator (TPA) for payment of bill" << endl;
                cout << endl;
            }
            cout << "Total amount to be paid " << total << endl;
            cout << endl;
            cout<<"********************************************************************************************"<<endl;
            cout << endl;
            break;
        }
    }
}
int main()
{
    cout<<"                      COVID-19 HOSPITAL MODEL"<<endl;
    int x = 0;
    while (true)
    {
        if (x != -1 && x != -2)
        {
            cout << endl
                 << "Choose any option: " << endl;
            cout << "1. Input record of new patient" << endl;
            cout << "2. Search patient record" << endl;
            cout << "3. Total no. of patients" << endl;
            cout << "4. No. of patients in specified district" << endl;
            cout << "5. Display all patients in alphabetical order" << endl;
            cout << "6. Delete record of a patient" << endl;
            cout << "7. Check guideleines for zone (by colour)" << endl;
            cout << "8. Number of empty beds available in the hospital right now" << endl;
             cout <<"9. Enter the details of plasma donor" << endl;
            cout<<"10. Search for plasma donor available "<<endl;
            cout<<"11. Total no of donor available same blood group:"<<endl;
            cout << "12. District wise Zone distribution" << endl;
            cout << "13. Maintain patient health record" << endl;
            cout << "14. Generate Medical bill of the patient " << endl;
            cout << "15. Exit" << endl;
            cin >> x;
        }
        if (x == 1 || x == -1)
        {
            Person p;
            cout << "Enter patient name: ";
            cin >> p.name;
            cout << "Enter patient age: ";
            cin >> p.age;
            cout << "Enter patient phoneno: ";
            cin >> p.phoneno;
            cout << "Enter patient district: ";
            cin >> p.district;
            cout << "If entered wrong data and want to re-enter input -1 else input 0: ";
            cin >> x;
            cout << endl;
            cout << endl;
            if (x == -1)
            {
                continue;
            }
            fstream fp,pr;
            fp.open("Covid Data.txt", ios_base::app);
            fp << p.name << " " << p.age << " " << p.phoneno << " " << p.district << endl; 
            fp.close();
        }
        else if (x == 2)
        {
            cout << "Search by 1.name or 2.phoneno: ";
            int n;
            cin >> n;
            if (n == 1)
            {
                string name;
                cout << "Name of patient: ";
                cin >> name;
                cout << endl;
                searchbyname(name);
            }
            else if (n == 2)
            {
                long long phoneno;
                cout << "Phoneno of patient: ";
                cin >> phoneno;
                cout << endl;
                searchbyphoneno(phoneno);
            }
        }
        else if (x == 3)
        {
            cout << "Total no. of Patients: " << TotalPatients() << endl;
        }
        else if (x == 4)
        {
            cout << "Enter district to search: ";
            string district;
            cin >> district;
            cout << "Patients in " << district << ": " << PatientsInDistrict(district) << endl;
            cout << endl;
        }
        else if (x == 5)
        {
            displayAll();
        }
        else if (x == 6)
        {
            cout << "Enter patient name: ";
            string name;
            cin >> name;
            Person p = DeleteRecord(name);
            cout << endl
                 << "This record is deleted: " << endl;
            p.display();
        }
        else if (x == 7)
        {
            int zone;
            cout << "Guidelines for zones";
            cout << "\nEnter the the colour of zone";
            cout << "\n1. Green \n2. Orange \n3. Red\n";
            cin >> zone;
            cout << "Prohibitions:\nTravel by air, rail, metro and inter-State movement by road\nSchools, colleges, and other educational and training/ coaching institutions\nhotels and restaurants\nCinema halls, malls, gyms, sports complexes etc.\nSocial, political, cultural and other kinds of gatherings\nReligious places/ places of worship for the public.";
            if (zone == 1)
            {
                cout << "\nBuses can operate with up to 50% seating capacity and bus depots can operate with up to 50% capacity";
            }
            else if (zone == 2)
            {
                cout << "\nInter-district movement of individuals and vehicles will be allowed for permitted activities only. Four wheeler vehicles will have a maximum of two passengers besides the driver and pillion riding will be allowed on two-wheelers. E-commerce is allowed for both essential and non-essential items in the orange zone.";
            }
            else if (zone == 3)
            {
                cout << "\nPlying of cycle rickshaws and auto-rickshaws; running of taxis and cab aggregators; intra-district and inter-district plying of buses; and, barbershops, spas and salons is prohibited.";
                cout << " Offices can open with a third of the staff. However, e-commerce activities are only allowed for essential services.";
            }
            else
            {
                cout << "Wrong input";
            }
            cout << endl;
        }
        else if (x == 8)
        {
            cout << "Total number of beds in the hospital: 350";
            cout << "\nNumber of empty beds available in the hospital: ";
            cout << 350 - TotalPatients();
            cout << endl;
        }
        else if(x==9 || x==-3)
        {
        	 
            Person p;
            cout << "Enter donor name: ";
            cin >> p.name;
            cout << "Enter donor age: ";
            cin >> p.age;
            cout << "Enter donor phoneno: ";
            cin >> p.phoneno;
            cout << "Enter donor district: ";
            cin >> p.district;
            cout<<"Enter the donor blood group:";
            cin>>p.plasma;
            cout << "If entered wrong data and want to re-enter input -3 else input 0: ";
            cin >> x;
            cout << endl;
            cout << endl;
            if (x == -3)
            {
                continue;
            }
            fstream fp;
            fp.open("Donor Data.txt", ios_base::app);
            fp << p.name << " " << p.age << " " << p.phoneno << " " << p.district <<" "<<p.plasma<<endl;
            fp.close();
        }
        else if(x==10)

      {   cout<<" Enter the blood group:";
            string plasma;
            cin>>plasma;
            searchbyplasma(plasma);
	
		}
		else if(x==11)
		{
			 cout << "Enter Blood group to be search: ";
            string plasma;
            cin >> plasma;
            cout << "Total no of donor of blood group " << plasma <<" is"<< ": " << SameDonor(plasma) << endl;
            cout << endl;
				}		
        
        else if (x == 12)
        {
            cout << "Enter district whose zone you want to know: ";
            string district;
            cin >> district;
            zone_distribution(district);
        }
        else if (x == 13 || x==-2)
        {
            patient p;
            cout << "Enter patient id ";
            cin >> p.pid;
            cout << "Enter patient name ";
            cin >> p.name;
            cout << "Total number of days patient received treatment ";
            cin >> p.days;
            cout << "Whether patient requires intensive care?(yes/no) ";
            cin >> p.intensiveCareNeeded;
            cout << "Whether rt pcr test was conducted along with rapid antigen test?(yes/no) " ;
            cin>>p.rt_pcr;
            cout << "Whether patient has medical insurance(yes/no) ";
            cin>>p.hasMedicalInsurance;
            cout << "If entered wrong data and want to re-enter input -2 else input 0: ";
            cin >> x;
            cout << endl;
            cout << endl;
            if (x == -2)
            {
                continue;
            }  
            fstream fp;
            fp.open("patientRecord.txt", ios_base::app);
            fp << p.pid << " " << p.name << " " << p.days << " " << p.intensiveCareNeeded << " " << p.rt_pcr << " " << p.hasMedicalInsurance << endl;
            fp.close();
        }
        else if(x==14){
            int pid;
            cout<<"Enter patient id whose bill has to be generated "<<endl;
            cin>>pid;
            generatebill(pid);
        }
        else if (x == 15)
        {
            break;
        }
        else if (x >15)
        {
            cout << "Wrong Input" << endl;
        }
    }
}