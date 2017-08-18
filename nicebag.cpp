#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class Bag{
public:
	int value;
	string name;
	list<Bag*> bags;
	Bag(int v,string n){
		this->value = v;
		this->name  = n;   
	}
	Bag(){
	 
	}
};

Bag * travel(Bag * b){
	if(b->bags.size() != 0){
		Bag * maxbag = b->bags.front();
		for(list<Bag*>::iterator it = b->bags.begin(); it != b->bags.end(); ++it){
		 	Bag * _bag = travel(*it);
		 	if(_bag->value >= maxbag->value ){
		 		maxbag = _bag;
		 	}
		}
		return maxbag;
	}else{
		return b;
	}
}


Bag * findnicebag(Bag * b){
	Bag * bag = new Bag();
	bag->bags.push_back(b);
	return travel(bag); 
}

int main(){

	Bag * a = new Bag(30,"a袋");
	Bag * b = new Bag(80,"b袋");
	Bag * c = new Bag(50,"c袋");
	Bag * d = new Bag(85,"d袋");
	Bag * e = new Bag(65,"e袋");
	Bag * f = new Bag(100,"f袋");
	Bag * g = new Bag(15,"g袋");
	Bag * h = new Bag(40,"h袋");

	c->bags.push_back(d);
	c->bags.push_back(e);
	c->bags.push_back(f);
	b->bags.push_back(g);
	b->bags.push_back(h);
	a->bags.push_back(c);
	a->bags.push_back(b);

	Bag * nicebag = findnicebag(a);
	cout<<"袋子中最有價值的是:"<<nicebag->name<<" 資產("<<nicebag->value<<")\n";
	return 0;
}