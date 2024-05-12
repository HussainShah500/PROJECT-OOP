#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class team{
	public:
	string name;
	int t_overs;
	int t_runs;
	int t_outs;
	
	team(){
	 name="didn`t enter yet";
	 t_overs=0;
	 t_runs=0;
	 t_outs=0;
	}
	
};

class player{
	public :
		string name ;
		int age ;
		int shirt_no ;
		
		// SETTER FUNTIONS
		
		void set_name(string name){
			this->name=name;
		}
		
		void set_age(int age){
			this->age=age;
		}
		
		void set_shirt_no(int shirt_no){
			this->shirt_no=shirt_no;
		}
		
		//GETTER FUNCTIONS
		
		string get_name(){
			return name;
		}
		
		int get_age(){
			return age;
		}
		
		int get_shirt_no(){
			return shirt_no ;
		}
		
};

class batsman :public player  {
	public:
	int runs;
	int p_balls;  //played balls
	int fiftys;
	int centerys;
	float strick_rate;
	float average;
	
	batsman(){
	 runs=0;
	 p_balls=0;  
	 fiftys=0;
	 centerys=0;
	 strick_rate=0.0;
	 average=0.0;
	}
	
	
		// SETTER FUNTIONS
		
		void set_p_balls(){
			p_balls++;
		}
		
		void set_runs(int runs){
			this->runs+=runs;
			if(runs>=50){
				set_fiftys();
			}
			else if(runs>=100){
				set_centerys();
			}
			else{
			}
		}
		
		void set_centerys(){
			centerys++;
		}
		
		void set_fiftys(){
			fiftys++;
		}
		
		void strick_rate_calculator(){
			strick_rate=(runs/p_balls)*100;
		}
		
		void average_calculator(float average){
			this->average=average;
		} 
	
		//GETTER FUNCTIONS
	
		int get_p_balls(){
			return p_balls;
		}
	
		int get_runs(){
			return runs;
		}
		
		int get_centerys(){
			return centerys;
		}
		
		int get_fiftys(){
			return fiftys;
		}
		
		float get_strick_rate(){
			return strick_rate;
		}
		
		float get_average (){
			return average;
		}
		
		
		
};

class bowler :public batsman {
	public :
		int runs_given;
		int d_overs;    //delivered overs
		int wickets;
		float economy;
		
		bowler(){
		 runs_given=0;
		 d_overs=0;    
		 wickets=0;
		 economy=0.0;
		}
		
		// SETTER FUNTIONS
		
		void economy_calculator (){
			economy=(float)runs_given/d_overs;
		}
		
		void set_runs_given(int runs_given){
			this->runs_given+=runs_given;
		}
		
		void set_d_overs(){
			d_overs++;
		}
		
		void set_wickets (){
			wickets++;
			
		}
		
		//GETTER FUNCTIONS
		
		int get_d_overs(){
			return d_overs;
		}
		
		int get_wickets(){
			return wickets;
		}
		
		int get_runs_given(){
			return runs_given;
		}
		
		float get_economy(){
			return economy;
		}
		
};

class keeper :public batsman {
	public:
	int catches;
	int stumps;
	
	keeper(){
	 catches=0;
	 stumps=0;
	}
	
	// SETTER FUNTIONS
		
		void set_catches (){
			catches++;
		}
		
		void set_stumps(){
			stumps++;
		}
		
	//GETTER FUNCTIONS
	
		int get_catches(){
			return catches;
		}
		
		int get_stumps(){
			return stumps;
		}
	
}; 

// check user's input
int check (int min,int max){
	int num;
   
     cout <<"Enter your choice:";
    while (!(cin >> num) || (num < min || num > max)) {
        cout << "Invalid input.Please enter the correct number :";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

//search batsman by name and return idex
int search (string name,const vector<batsman>& vec){
	for (int i=0;i<11;i++){
		if(vec.at(i).name==name){
			return i;
		}
		
		else{
		}
	}
}

//search bowler by name and return idex
int search (string name,const vector<bowler>& vec){
	for (int i=0;i<5;i++){
		if(vec.at(i).name==name){
			return i;
		}
	
		else{
		}
	}
}




int main ()
{
	int any_no;
	int runs=0;
	int over=0;
	int balls=0;
	int out=0;
	string name ;
	int age ;
	int shirt_no ;
	int wickets;
	float average;
	int total_runs=0;
	int num;
	int indexA=0;
	int indexB=0;
	int indexC=0;
	// vectors for objects of both teams
	vector<batsman>batsman_list1 (11);
	vector<bowler>bowler_list1 (5);
	vector<batsman>batsman_list2 (11);
	vector<bowler>bowler_list2 (5);
	keeper keeper1;
	keeper keeper2;
	team team_a;
	team team_b;
	int counter=0;
	
	cout <<"\\/\\/\\/\\/\\/\\-- CRICKET NAME HA JANOON KA --/\\/\\/\\/\\/\\/\\ \n"<<endl;
	
    for (int i=0;i==0;i=0)
    {
    	cout<<"\n----MAIN MENU-----\n"<<endl;
    	cout<<"\nCHOOSE OPTION\n"<<endl;
		cout<<"INPUT MATCH DATA        ----------> ENTER 1"<<endl;
		cout<<"START MATCH             ----------> ENTER 2"<<endl;
		cout<<"DISPLAY SUMMARY         ----------> ENTER 3"<<endl;
		cout<<"EXIT PROGRAME           ----------> ENTER 4"<<endl;
		
		cin>>any_no;
		cin.ignore();
		if (cin.fail())// to check the correct input from the user
		{
			cout<<"Please enter the corrrect option i-e 1,2,3 or 4"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');		
		}
		else if(any_no==1)
		{
			
			cout <<"Enter the names for teams"<<endl;
			cout <<"Team A:";
			getline(cin,team_a.name);
		//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout <<"Team B:";
			getline(cin,team_b.name);
		//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
			cout <<"=============================="<<endl;	
			cout <<"input data of team "<<team_a.name<<endl;
			cout <<"=============================="<<endl;
			
			int l=0;
			for ( int j=1;l<5;l++,j++)
			{
				cout <<"Batsman "<<j<<":"<<endl;
				cout <<"Name : ";
				getline(cin,name);
				
				batsman_list1[l].name=name;
				for(int i=0;i==0;)
				{
					cout <<"Age : ";
					cin>>age;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				batsman_list1[l].age=age;
				for(int i=0;i==0;)
				{
					cout <<"Shirt No : ";
					cin>>shirt_no;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				
				batsman_list1[l].shirt_no=shirt_no;
				cout <<endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	}
	    	
	    	for (int k=0,j=1;k<5;j++,k++){
				
				cout <<"Bowler "<<j<<":"<<endl;
				cout <<"Name : ";
				getline(cin,name);
				 bowler_list1[k].set_name(name);
				 batsman_list1[l].set_name(name);
				 
			for(int i=0;i==0;)
				{
					cout <<"Age : ";
					cin>>age;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				} 
				 bowler_list1[k].set_age(age);
				 batsman_list1[l].set_age(age);
				 
			for(int i=0;i==0;)
				{
					cout <<"Shirt No : ";
					cin>>shirt_no;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				 bowler_list1[k].set_shirt_no(shirt_no);
				 batsman_list1[l].set_shirt_no(shirt_no);
				 
				cout <<endl;
				l++;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	}
	    	
	    	// keeper1 input
	    	
	    		cout <<"keeper "<<endl;
				cout <<"Name : ";
				getline(cin,name);
				keeper1.name=name;
				batsman_list1[l].set_name(name);
				for(int i=0;i==0;)
				{
					cout <<"Age : ";
					cin>>age;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				} 
				keeper1.age=age;
				batsman_list1[l].set_age(age);
				for(int i=0;i==0;)
				{
					cout <<"Shirt No : ";
					cin>>shirt_no;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				keeper1.shirt_no=shirt_no;
				batsman_list1[l].set_shirt_no(shirt_no);
	    	
			cout <<"=============================="<<endl;
			cout <<"input data of team "<<team_b.name<<endl;
			cout <<"=============================="<<endl;
			
			 l=0;	
			for (int j=1;l<5;l++,j++){
				
				cout <<"Batsman "<<j<<":"<<endl;
				cout <<"Name : ";
				getline(cin, batsman_list2[l].name);
				for(int i=0;i==0;)
				{
					cout <<"Age : ";
					cin>> batsman_list2[l].age;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				} 
				for(int i=0;i==0;)
				{
					cout <<"Shirt No : ";
					cin>> batsman_list2[l].shirt_no;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				} 
				cout <<endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	}
	    	
	    	for (int j=1,k=0;k<5;i++,j++,k++){
				
				cout <<"Bowler "<<j<<":"<<endl;
				cout <<"Name : ";
				getline(cin,name);
				bowler_list2[k].name=name;
				batsman_list2[l].name=name;
				 
				{
					cout <<"Age : ";
					cin>>age;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				} 
				 bowler_list2[k].age=age;
				 batsman_list2[l].age=age;
				 
				for(int i=0;i==0;)
				{
					cout <<"Shirt No : ";
					cin>>shirt_no;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				 bowler_list2[k].shirt_no=shirt_no;
				 batsman_list2[l].shirt_no=shirt_no;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	}
	    	
	    	// keeper2 input
	    	
	    		cout <<"keeper "<<endl;
				cout <<"Name : ";
				getline(cin,name);
				keeper2.name=name;
				batsman_list1[l].name=name;
				for(int i=0;i==0;)
				{
					cout <<"Age : ";
					cin>>age;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				} 
				 keeper2.age=age;
				batsman_list1[l].age=age;
				
				for(int i=0;i==0;)
				{
					cout <<"Shirt No : ";
					cin>>shirt_no;
					if(cin.fail())
					{
						cout<<"Please enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					break;
				}
				keeper2.shirt_no=shirt_no;	
				batsman_list1[l].shirt_no=shirt_no;
				
				cout <<"=============================="<<endl;
		}
		else if (any_no==2)
		{
				cout <<endl;
				cout <<"=========MATCH BEGAN==========\n"<<endl<<endl;
				
				cout <<"---------1st inning ----------"<<endl;
				cout <<"Enter the name of openers:\nA:";
				
					cin>>name;
				    indexA=search(name,batsman_list1);
				   
				
				
				cout <<"B:";
			
			
					cin>>name;
				    indexB=search(name,batsman_list1);
				   
				cout <<"Enter the name of bowler: ";
				
					cin>>name;
				    indexC=search(name,bowler_list1);
				   
				
				
				for(int over=0;over<5;over++){
					
				cout <<total_runs<<" - "<<out<<"  ||  "<<over<<"."<<balls<<" || "<<batsman_list1[indexA].name<<"-->"<<batsman_list1[indexA].runs<<" | "<<batsman_list1[indexB].name<<"-->"<<batsman_list1[indexB].runs<<endl;
				cout <<bowler_list2[indexC].name<<"-->"<<bowler_list2[indexC].wickets<<endl;
				
					for (balls=1;balls<7;balls++){
				cout <<"Ball "<<balls<<" delivered:"<<endl;
				cout <<"1--->True ball"<<endl;
				cout <<"2--->NO ball"<<endl;
				cout <<"3--->Wide ball"<<endl;
				 num= check(1,3);
				
				if(num==1){
					cout <<"1--->Runs\n2--->out"<<endl;
					num= check(1,2);
					if(num==1){
						cout<<"runs:";
						cin>>runs;
						total_runs=total_runs+runs;
						batsman_list1[indexA].set_runs(runs);
						
							if((runs%2)!=0){
								int temp_index=indexA;
								indexA=indexB;
								indexB=temp_index;
							}
					}
					else{
						
						cout <<"1--->bold"<<endl;
						cout <<"2--->catch by keeper"<<endl;
						cout <<"3--->stumps";
						cout <<"4--->Run Out"<<endl;
						num=check(1,4);
						if(num==1){
							out++;
							cout <<"bravo!! "<<batsman_list1[indexA].get_name()<<"has been bold by "<<bowler_list2[indexC].get_name()<<endl;
							bowler_list2[indexC].set_wickets();
							cout <<"Enter next player"<<endl;
							do{
								cin>>name;
				   				indexA=search(name,batsman_list1);
				   				if(indexA>=0){
				    					break ;
									}		
									else{
										cout <<"invalid input .please enter valid player"<<endl;
									}
								}while(true);
						}
						else if(num==2){
							out++;
							
							cout <<"bravo!! edged and caught by wicket keeper "<<keeper2.get_name()<<endl;
							bowler_list2[indexC].set_wickets();
							keeper2.set_catches();
							cout <<"Enter next player"<<endl;
							do{
									cin>>name;
				   					 indexA=search(name,batsman_list1);
				   					 if(indexA>=0){
				   					 	break ;
									}
										else{
											cout <<"invalid input .please enter valid player"<<endl;
											}
								}while(true);
						}
						else if(num==3){
							out++;
							
							cout <<"bravo!! "<<batsman_list1[indexA].get_name()<<"has been stumped by "<<keeper2.get_name()<<endl;
							bowler_list2[indexC].set_wickets();
							keeper2.set_stumps();
							cout <<"Enter next player"<<endl;
							do{
								cin>>name;
				  					  indexA=search(name,batsman_list1);
				   				 if(indexA>=0){
				   						 	break ;
									}
										else{
										cout <<"invalid input .please enter valid player"<<endl;
										}
									}while(true);
						}
						else{
							out++;
							
							cout <<"Enter next player"<<endl;
							cin>>name;
							indexA=search(name,batsman_list1);
						}
					}
		
				}
				
				
				else if(num==2){
					cout<<"runs:";
						cin>>runs;
						total_runs=total_runs+runs+1;
						balls--;
						batsman_list1[indexA].set_runs(runs);
						
							if((runs%2)!=0){
								int temp_index=indexA;
								indexA=indexB;
								indexB=temp_index;
							}
							
				}
				
				else{
					cout<<"runs:";
						cin>>runs;
						total_runs=total_runs+runs+1;
						balls--;
						
							if((runs%2)!=0){
								int temp_index=indexA;
								indexA=indexB;
								indexB=temp_index;
							}
				}
				
				cout <<total_runs<<" - "<<out<<"  ||  "<<over<<"."<<balls<<" || "<<batsman_list1[indexA].get_name()<<"-->"<<batsman_list1[indexA].get_runs()<<" | "<<batsman_list1[indexB].get_name()<<"-->"<<batsman_list1[indexB].get_runs()<<endl;
				cout <<bowler_list1[indexC].get_name()<<"-->"<<bowler_list1[indexC].get_wickets()<<endl;
				
				if(out==10){ break ;}
			}
						
					if(out==10){
						break;
					}	
				cout <<"Enter the name of bowler: ";
				cin>>name;
				indexC=search(name,bowler_list2);
				}
				
				team_a.t_runs=total_runs;
				team_a.t_outs=out;
				team_a.t_overs=over;
				
				
				int target =total_runs;
				total_runs=0;
				out=0;
				over=0;
				
				
				cout <<"******************************"<<endl<<endl;
				cout <<"---------2st inning ----------"<<endl;
				cout <<"Enter the name of openers:\nA:";
				
				cin>>name;
				indexA=search(name,batsman_list2);
				
				cout <<"B:";
			
				cin>>name;
				indexB=search(name,batsman_list2);
			
				cout <<"Enter the name of bowler: ";
				cin>>name;
				indexC=search(name,bowler_list1);
				
				for(int over=0;over<5;over++){
					
				cout <<total_runs<<" - "<<out<<"  ||  "<<over<<"."<<balls<<" || "<<batsman_list2[indexA].name<<"-->"<<batsman_list2[indexA].runs<<" | "<<batsman_list2[indexB].name<<"-->"<<batsman_list2[indexB].runs<<endl;
				cout <<bowler_list1[indexC].name<<"-->"<<bowler_list1[indexC].wickets<<endl;
				
				for (balls=1;balls<7;balls++){
				cout <<"Ball "<<balls<<" delivered:"<<endl;
				cout <<"1--->True ball"<<endl;
				cout <<"2--->NO ball"<<endl;
				cout <<"3--->Wide ball"<<endl;
				 num=check(1,3);
				
				if(num==1){
					cout <<"1--->Runs\n2--->out"<<endl;
					cin>>num;
					if(num==1){
						cout<<"runs:";
						cin>>runs;
						total_runs=total_runs+runs;
						batsman_list2[indexA].set_runs(runs);
						
							if((runs%2)!=0){
								int temp_index=indexA;
								indexA=indexB;
								indexB=temp_index;
							}
					}
					else{
						
						cout <<"1--->bold"<<endl;
						cout <<"2--->catch by keeper"<<endl;
						cout <<"3--->stumps";
						cout <<"4--->Run Out"<<endl;
						num=check(1,4);
						if(num==1){
							out++;
							cout <<"bravo!! "<<batsman_list2[indexA].get_name()<<"has been bold by "<<bowler_list1[indexC].get_name()<<endl;
							bowler_list1[indexC].set_wickets();
							cout <<"Enter next player"<<endl;
							cin>>name;
							indexA=search(name,batsman_list2);
						}
						else if(num==2){
							out++;
							
							cout <<"bravo!! edged and caught by wicket keeper "<<keeper2.get_name()<<endl;
							bowler_list1[indexC].set_wickets();
							keeper2.set_catches();
							cout <<"Enter next player"<<endl;
							cin>>name;
							indexA=search(name,batsman_list2);
						}
						else if(num==3){
							out++;
							
							cout <<"bravo!! "<<batsman_list2[indexA].get_name()<<"has been stumped by "<<keeper1.get_name()<<endl;
							bowler_list2[indexC].set_wickets();
							keeper1.set_stumps();
							cout <<"Enter next player"<<endl;
							cin>>name;
							indexA=search(name,batsman_list1);
						}
						else{
							out++;
							
							cout <<"Enter next player"<<endl;
							cin>>name;
							indexA=search(name,batsman_list2);
						}
					}
		
				}
				
				
				else if(num==2){
					cout<<"runs:";
						cin>>runs;
						total_runs=total_runs+runs+1;
						balls--;
						batsman_list2[indexA].set_runs(runs);
						if(total_runs>>target){ break;	}
						
							if((runs%2)!=0){
								int temp_index=indexA;
								indexA=indexB;
								indexB=temp_index;
							}
							
				}
				
				else{
					cout<<"runs:";
						cin>>runs;
						total_runs=total_runs+runs+1;
						balls--;
						
						
							if((runs%2)!=0){
								int temp_index=indexA;
								indexA=indexB;
								indexB=temp_index;
							}
				}
				
				cout <<total_runs<<" - "<<out<<"  ||  "<<over<<"."<<balls<<" || "<<batsman_list2[indexA].get_name()<<"-->"<<batsman_list2[indexA].get_runs()<<" | "<<batsman_list2[indexB].get_name()<<"-->"<<batsman_list2[indexB].get_runs()<<endl;
				cout <<bowler_list2[indexC].get_name()<<"-->"<<bowler_list2[indexC].get_wickets()<<endl;
				if(out==10){ break ;}
				if(total_runs>>target){ break; }
			}
				if(out==10){ break ;}
				if(total_runs>>target){ break; }
				
				cout <<"Enter the name of next bowler: ";
				cin>>name;
				indexC=search(name,bowler_list1);	
					
				}
				
				team_b.t_runs=total_runs;
				team_b.t_outs=out;
				team_b.t_overs=over;
			counter++;
		}
		else if (any_no==3)	
		{
			if (counter<2)
			{
				cout<<"first input data and start match"<<endl;
			}
			else if(counter==2)
			{
					if(team_a.t_runs>>team_b.t_runs){
					cout <<"CONGRAGULATION TO TEAM "<<team_a.name<<endl;
					cout <<team_a.name<<" won by"<<(team_a.t_runs)-(team_b.t_runs)<<" runs"<<endl;
				}
				else if (team_b.t_runs>>team_a.t_runs){
					cout <<"CONGRAGULATION TO TEAM "<<team_b.name<<endl;
					cout <<team_b.name<<" won by"<<10-(team_b.t_outs)<<" wickets"<<endl;
				}
				else{
					cout <<"match has been draw"<<endl;
				}
				
				cout <<"SCORE CARD TEAM "<<team_a.name<<endl;
				cout <<"BATING RESULT"<<endl;
				cout <<"TOTAL :::"<<team_a.t_runs<<" - "<<team_a.t_outs;
				
				for (int i=0;i<11;i++){
					cout <<"NAME:"<<batsman_list1[i].get_name()<<" || RUNS:"<<batsman_list1[i].get_runs() <<" || BALLS:"<<batsman_list1[i].get_p_balls()<<" || STRIKE RATE:"<<batsman_list1[i].get_strick_rate()<<" ||FIFTYS:"<<batsman_list1[i].get_fiftys()<<" ||CENTERYS:"<<batsman_list1[i].get_centerys() <<endl;
					cout <<endl;
				}
				
				cout <<"BALLING RESULT"<<endl;
				
				for (int i=0;i<5;i++){
					cout <<"NAME:"<<bowler_list1[i].get_name()<<" || WICKETS:"<<bowler_list1[i].get_wickets() <<" || BALLS:"<<(bowler_list1[i].get_d_overs())*6<<" || RUNS:"<<bowler_list1[i].get_runs_given()<<" || ECONOMY:"<<bowler_list1[i].get_economy()<<endl;
					cout <<endl;
				}
				
				
				cout <<"SCORE CARD TEAM "<<team_a.name<<endl;
				cout <<"BATING RESULT"<<endl;
				cout <<"TOTAL :::"<<team_b.t_runs<<" - "<<team_b.t_outs;
				
				for (int i=0;i<11;i++){
					cout <<"NAME:"<<batsman_list2[i].get_name()<<" || RUNS:"<<batsman_list2[i].get_runs() <<" || BALLS:"<<batsman_list2[i].get_p_balls()<<" || STRIKE RATE:"<<batsman_list2[i].get_strick_rate()<<" ||FIFTYS:"<<batsman_list2[i].get_fiftys()<<" ||CENTERYS:"<<batsman_list2[i].get_centerys() <<endl;
					cout <<endl;
				}
				
				cout <<"BALLING RESULT"<<endl;
				
				for (int i=0;i<5;i++){
					cout <<"NAME:"<<bowler_list2[i].get_name()<<" || WICKETS:"<<bowler_list2[i].get_wickets() <<" || BALLS:"<<(bowler_list2[i].get_d_overs())*6<<" || RUNS:"<<bowler_list2[i].get_runs_given()<<" || ECONOMY:"<<bowler_list2[i].get_economy()<<endl;
					cout <<endl;
				}
			}
			else{}
			
		}
		else if(any_no==4)
		{
			return 0;
		}
		else
		{
			cout<<"Please enter the correct option i-e 1,2,3 or 4"<<endl;
			continue;
		}
	}
		
}

















