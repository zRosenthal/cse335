#ifndef NODE_H_
#define NODE_H_
#include <string>
class Visitor;
class Node
{
public:
	Node(const std::string &name);
	virtual ~Node();
        Node(const Node &v)=default;
        Node& operator=(const Node &rhs)=default;
	std::string GetName() const {return mName;}
	virtual std::string GetFormatName() = 0;
	void SetName(const std::string &name) {mName = name;}
	virtual void Accept(Visitor* visitor) = 0;
	virtual void Print() = 0;
protected:
	Node(){};

private:
	std::string mName;
};

#endif /* NODE_H_ */
