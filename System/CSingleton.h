#pragma once
template <typename T>

class CSingleton
{
protected:
	CSingleton() {};
	virtual ~CSingleton() {};
private:
	CSingleton(const CSingleton&) {};
	CSingleton& operator=(const CSingleton&) {};
public:
	static T* getInstance() {
		static T instance;
		return &instance;
	}
};

