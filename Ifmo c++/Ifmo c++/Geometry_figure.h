#pragma once

class IGeoFig {
public:
	virtual double square() = 0;
	virtual double perimeter() = 0;
};

class CVector2D {
public:
	double x, y;
};

class IPhysObject {
public:
	virtual double mass()const = 0;
	virtual CVector2D position() = 0;
	virtual bool operator==(const IPhysObject& ob)const = 0;
	virtual bool operator<(const IPhysObject& ob)const = 0;
};
class IPrintable {
public:
	virtual void draw() = 0;
};
class IDialogInitiable {
public:
	virtual void initFromDialog() = 0;
};
class BaseCObject {
public:
	virtual const char* classname() = 0;
	virtual unsigned int size() = 0;
};

class GeoObj :public IPhysObject,public IPrintable,public IDialogInitiable,public BaseCObject,public IGeoFig {

};

class Circle :public GeoObj {
	CVector2D c;
	double r;
	double m;
public:
	double square();
	double perimeter();
	double mass()const;
	CVector2D position();
	bool operator==(const IPhysObject& ob)const;
	bool operator<(const IPhysObject& ob)const;
	void draw();
	void initFromDialog();
	const char* classname();
	unsigned int size();
};

class Rectange :public GeoObj {
	double x1, y1, x2, y2, x3, y3;
	double m;
public:
	double square();
	double perimeter();
	double mass()const;
	CVector2D position();
	bool operator==(const IPhysObject& ob)const;
	bool operator<(const IPhysObject& ob)const;
	void draw();
	void initFromDialog();
	const char* classname();
	unsigned int size();
};