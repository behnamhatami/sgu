#include <iostream>
#include <vector>
using namespace std;

class bignum{
	bool sign;
	vector<int> arr;

public:
	bignum(const string &s){
		for(int i = s.size() - 1; i > 0; i--)
			arr.push_back(s[i]-'0');
		
		if(s[0] == '-')
			sign = true;
		else sign = false;
	}

	bignum(const string &s, bool sign){
		for(int i = s.size() - 1; i >= 0; i--)
			arr.push_back(s[i]-'0');
		this->sign = sign; 
	}

	bignum(const bignum &b, bool sign){
		arr = b.arr;
		this->sign = sign;
	}

	bignum(const int pow){
		for(int i = 0; i < pow; i++)
			arr.push_back(0);
		arr.push_back(1);
		sign = false;
	}

	bignum abs() const{
		return *(new bignum(*this, false));
	}

	bignum reverse() const{
		return *(new bignum(*this, !sign));
	}

	int compare(const bignum &other) const{
		if(other.sign != sign)
			return sign ? -1 : 1;

		if(arr.size() != other.arr.size())
			return (arr.size() < other.arr.size() ? -1 : 1);
		
		for(int i = arr.size() - 1; i>= 0; i--)
			if(arr[i] != other.arr[i])
				return (arr[i] < other.arr[i] ? -1 : 1) * (sign ? -1 : 1);

		return 0;
	}

	void normalize(){
		for(unsigned int i = 0; i < arr.size(); i++){
			int car = arr[i] / 10;
			arr[i] %= 10;
			if(car > 0){
				if(i + 1 < arr.size())
					arr[i + 1] += car;
				else arr.push_back(car);
			}
		}

		while(arr.size() > 1 && arr[arr.size() - 1] == 0)
			arr.pop_back();
	}

	bignum add(const bignum &other) const{
		if(other.sign != sign)
			return minus(other.reverse());

		bignum ret(*this, sign);
		
		for(unsigned int i = 0, j = 0; i < ret.arr.size() || j < other.arr.size(); i++, j++){
			int tp = j < other.arr.size() ? other.arr[j] : 0;
			if(i < ret.arr.size())
				ret.arr[i] += tp;
			else ret.arr.push_back(tp); 
		}

		ret.normalize();
		return ret;
	}


	bignum multiply(const bignum &other) const{
		bignum ret("+0");
		for(unsigned int i = 0; i < other.arr.size(); i++)
			ret = ret.add(this->multiply(other.arr[i],  i));
		return ret;
	}

	bignum multiply(const int ct, const int pow) const{
		bignum ret(pow);
		ret.arr.pop_back();
		for(unsigned int i = 0; i < arr.size(); i++)
			ret.arr.push_back(arr[i]);
		return ret.multiply(ct);
	}

	bignum multiply(const int ct) const{
		bignum ret(*this, sign);
		for(unsigned int i = 0; i < ret.arr.size(); i++)
			ret.arr[i] *= ct;

		ret.normalize();
		return ret;
	}

	bignum divide(const int div) const{ // just for one digit
		bignum ret(*this, sign);
		for(int i = arr.size() - 1, car = 0; i >= 0; i--){
			ret.arr[i] = (arr[i] + car * 10)/div;
			car = (arr[i] + car * 10) % div;
		}

		ret.normalize();
		return ret;
	}

	bignum minus(const bignum &other) const{
		if(other.sign != sign)
			return add(other.reverse());

		return *this;
	}

	string toString(){
		char* ret = new char[arr.size() + 1];
		ret[arr.size()] = 0;
		for(unsigned int i = 0; i < arr.size(); i++)
			ret[arr.size() - 1 - i] = (char)(arr[i] + '0');


		string out = string(ret);
		if(sign)
			out = "-" + out;

		return out;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	bignum in(s, false);

	bignum first((s.size() - 1)/2), last((s.size() + 1) / 2);

	while(first.add(bignum(0)).compare(last) < 0){
		bignum mid = first.add(last).divide(2);
		if(mid.multiply(mid).compare(in) <= 0)
			first = mid;
		else last = mid;
	}

	cout << first.toString() << endl;
	return 0;
}