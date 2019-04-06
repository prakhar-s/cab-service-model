#include<iostream>
#include<bits/stdc++.h>
#include<iterator>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map< string, list< pair < string, int > > >m;
map< string, list< pair < string, string > > >carcat;
map<string,string>location;

map<string ,string>path;
map<string,int>DriverDistance;
map<string,string>drivercontact;
map<string,string>drivername;


void addedge(string u,string v,int d)
{
  m[u].push_back(make_pair(v,d));
  m[v].push_back(make_pair(u,d));
}

void addcategorie()
{
  carcat["micro"].push_back(make_pair("Swift dezire","UP 14 A 1234"));
  drivercontact["UP 14 A 1234"]="8948530987";
  drivername["UP 14 A 1234"]="Shivam Singh";

  carcat["micro"].push_back(make_pair("Wagon R","UP 14 B 1000"));
  drivercontact["UP 14 B 1000"]="9876543210";
  drivername["UP 14 B 1000"]="Yasharth Pathak";

  carcat["micro"].push_back(make_pair("Ritz","UP 14 C 1200"));
  drivercontact["UP 14 C 1200"]="9878965474";
  drivername["UP 14 A 1234"]="Somil Rastogi";

  carcat["micro"].push_back(make_pair("Beat","UP 14 D 1300"));
  drivercontact["UP 14 D 1300"]="8977678513";
  drivername["UP 14 D 1300"]="Akash Misra";

  carcat["mini"].push_back(make_pair("Swift Dezire","UP 14 E 1400"));
  drivercontact["UP 14 E 1400"]="8948778644";
  drivername["UP 14 E 1400"]="Jitesh Goel";

  carcat["mini"].push_back(make_pair("Amaze","UP 14 AB 1500"));
  drivercontact["UP 14 AB 1500"]="8948123321";
  drivername["UP 14 AB 1500"]="Vaibhav Asthana";


  carcat["mini"].push_back(make_pair("Xcent","UP 14 BC 1601"));
  drivercontact["UP 14 BC 1601"]="8948778934";
  drivername["UP 14 BC 1601"]="Arjit Kar";


  carcat["suv"].push_back(make_pair("Ertiga","UP 14 CD 1877"));
  drivercontact["UP 14 CD 1877"]="8948773027";
  drivername["UP 14 CD 1877"]="Harsh Kumar Singh rajput";

  carcat["suv"].push_back(make_pair("Scorpio","UP 14 DE 9836"));
  drivercontact["UP 14 DE 9836"]="7869654322";
  drivername["UP 14 DE 9836"]="Pramod Dubey";

  carcat["suv"].push_back(make_pair("Innova","UP 14 GF 1867"));
  drivercontact["UP 14 GF 1867"]="7811600554";
  drivername["UP 14 GF 1867"]="Deepak Sharma";

  carcat["suv"].push_back(make_pair("Safari Dicor","UP 14 FX 6301"));
  drivercontact["UP 14 FX 6301"]="8948776100";
  drivername["UP 14 FX 6301"]="Ravi Thakur";

  carcat["suv"].push_back(make_pair("Bolero","UP 14 ZX 0007"));
  drivercontact["UP 14 ZX 0007"]="7799546720";
  drivername["UP 14 ZX 0007"]="Sudama Pathak";

}

 void display_locations()
{
  for(auto i:m)
  {
    cout<<i.first<<endl<<endl;
  }
}

float dijkstra(string src,string destination)
{
  map<string,int>distance;
  for(auto i:m)
  {
    distance[i.first]=INT_MAX;
  }
  set<pair<int,string > >s;
  distance[src]=0;

  s.insert(make_pair(0,src));
  while(!s.empty())
  {
    auto p=*(s.begin());
    string node=p.second;
    int node_dist=p.first;
    s.erase(s.begin());

    for(auto childpair:m[node])
    {

      if((node_dist+childpair.second) <distance[childpair.first])
      {
        string dest=childpair.first;
        auto f=s.find(make_pair(distance[dest],dest));
        if(f!=s.end())
        {
          s.erase(p);
        }
        distance[dest]=node_dist+childpair.second;
        s.insert(make_pair(distance[dest],dest));
        path[dest]=node;
      }
    }
  }
return(distance[destination]);


}


void Path(string s,string d)
{
  vector<string>route;
  string x;

  x=d;
   for(auto i:path)
   {
      auto t=path.find(x);

    route.push_back(t->second);
    if(t->second==s)
    {
      break;
    }
      x=t->second;
   }

   for(int j=route.size()-1;j>=0;j--)
   {
     if(j==0)
     {
       cout<<route[j];
     }
     else
     {
        cout<<route[j]<<" -> ";
     }

   }
   cout<<" -> "<<d;

}

void details(string cat,string source,string destination)
{
  string temp;


  int flag=0;
  float basefair;
  float extracost;
  float totalcost;

  if(cat=="micro")
  {

    basefair=50.00;
    extracost=8.00;

    auto t=carcat.find("micro");
    for(auto i:carcat["micro"])
    {
        cout<<"Enter location of "<<i.first<<endl;

        getline(cin,temp);
        cout<<endl;
        location[i.first]=temp;
     }
   }

  else if(cat=="mini")
   {
     basefair=65.00;
     extracost=10.00;
     auto t=carcat.find("mini");
     for(auto i:carcat["mini"])
     {
         cout<<"Enter location of "<<i.first<<endl;
         getline(cin,temp);
         cout<<endl;
         location[i.first]=temp;
      }
    }

    else if(cat=="suv")
    {
      basefair=80.00;
      extracost=13.00;
      auto t=carcat.find("suv");
      for(auto i:carcat["suv"])
      {
          cout<<"Enter location of "<<i.first<<endl;
          getline(cin,temp);
          cout<<endl;
          location[i.first]=temp;
       }
     }
     else
     {
       flag++;
       cout<<endl<<endl<<"Please enter the correct categorie from the above given options only"<<endl;
     }
     if(flag==0)
     {
       for(auto i:location)
       {
          DriverDistance[i.first]=dijkstra(i.second,source);
          cout<<"Distance of "<<i.first<<" from "<<source<<" is "<<DriverDistance[i.first]<<" km"<<endl;
       }

       string assignedcar;
       auto p=*(DriverDistance.begin());

       int d=p.second;

       for(auto i:DriverDistance)
       {
          if(i.second<=d)
          {
            d=i.second;
            assignedcar=i.first;
          }

       }

      cout<<endl<<endl<<"assinged car for the pickup is "<<assignedcar<<" and it is "<<d<<" km away from the pickup point";
      float JourneyDistance=dijkstra(source,destination);
      float waitingtime=((float)d)/45;
      waitingtime=waitingtime*60;
      cout<<endl<<endl<<"Route taken by the cab to reach the pickup point is"<<endl;
      string g=location[assignedcar];
      dijkstra(g,source);
      Path(g,source);
      path.clear();

       cout<<endl<<"waiting time for the pickup is "<<waitingtime<<" minutes"<<endl;
       cout<<endl<<"Journey distance is "<<JourneyDistance<<" km."<<endl;
       cout<<endl<<"route that the cab will take from the pickup point to the the droping point is"<<endl;
       dijkstra(source,destination);
       Path(source,destination);

       totalcost=basefair+((JourneyDistance-5)*extracost);
       cout<<endl<<endl<<"Ride Estimate is Rs "<<totalcost;

      string numberplate;
      string contact;
      string name;
       for(auto i:carcat[cat])
       {
         if(i.first==assignedcar)
         {
           numberplate=i.second;
           break;
         }
       }
     contact=drivercontact[numberplate];
     name=drivername[numberplate];
     cout<<endl<<endl<<"Assigned car : "<<assignedcar;
     cout<<endl<<"Cab number plate: "<<numberplate;
     cout<<endl<<"Driver name : "<<name;
     cout<<endl<<"Driver's contact number : "<<contact<<endl<<endl<<endl;
   }
}


int main()
{

  addedge("DWARKA","KASHMIRI GATE",8);
  addedge("DWARKA","KAILASH",10);
  addedge("DWARKA","MAYUR VIHAR",7);
  addedge("DWARKA","RAJIV CHOWK",4);
  addedge("KASHMIRI GATE","INDIRAPURAM",4);
  addedge("KASHMIRI GATE","KALUSARAI",9);
  addedge("RAJIV CHOWK","NEHRU PLACE",25);
  addedge("RAJIV CHOWK","SAKET",15);
  addedge("HAUZ KHAZ","CHANDNI CHOWK",5);
  addedge("HAUZ KHAZ","MAYUR VIHAR",4);
  addedge("HAUZ KHAZ","PARI CHOWK",13);
  addedge("MAYUR VIHAR","LAXMI NAGAR",8);
  addedge("MAYUR VIHAR","KAROL BAGH",11);
  addedge("INDIRAPURAM","KAILASH",2);
  addedge("KAILASH","LAXMI NAGAR",2);
  addedge("PARI CHOWK","NEHRU PLACE",14);
  addedge("PARI CHOWK","KAROL BAGH",5);
  addedge("PARI CHOWK","LAXMI NAGAR",16);
  addedge("LAXMI NAGAR","KALUSARAI",3);
  addedge("KAROL BAGH","SAKET",6);
  addedge("CHANDNI CHOWK","KAUSHAMBHI",6);




  cout<<"CHOOSE YOUR LOCATIONS FROM THE BELOW MENTIONED LOCATIONS ONLY"<<endl;
  cout<<endl<<endl<<endl;
  display_locations();
  cout<<"--------------------------------------------------------------------"<<endl;

  string source;
  string destination;
  string sdriver;
  string cat;
  cout<<"--------------------------------------------------------------------"<<endl;
  cout<<"FOR THE CUSTOMER"<<endl;

  cout<<"Enter the source"<<endl;
  getline(cin,source);

  cout<<"Enter your destination"<<endl;
  getline(cin,destination);

  addcategorie();
  cout<<"choose your car categorie preference from the options given below"<<endl;
  int k=0;
  cout<<endl;
  for(auto i:carcat)
  {

    cout<<k<<") "<<i.first<<endl;
    k++;
  }

  getline(cin,cat);
  cout<<"-------------------------------------------------------------------"<<endl;
  cout<<"FOR DRIVER DETAILS"<<endl;
  details(cat,source,destination);


}
