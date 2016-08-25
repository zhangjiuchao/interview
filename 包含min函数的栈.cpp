#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class mStackElement
{
public:
    mStackElement(T ele,T m): data(ele), minEle(m) {}
    T data;
    T minEle;
};

template<typename T>
class mStack
{
private:
    vector< mStackElement<T>* > elements;
public:
    T SminEle()
    {
        mStackElement<T> *top = elements.back();
        return top->minEle;
    }

    bool empty(){return elements.empty();}

    void Spush(T newElement)
    {
        T minEle = newElement;
        if(!elements.empty())
        {
            mStackElement<T> *top = elements.back();
            if(top->minEle < minEle)
                minEle = top->minEle;
        }

        mStackElement<T> *newtop = new mStackElement<T>(newElement,minEle);
        elements.push_back(newtop);
    }

    T Spop()
    {
        mStackElement<T> *top = elements.back();
        elements.pop_back();
        T ele = top->data;
        delete top;
        return ele;
    }
};



int main()
{
    mStack<int> S;
    S.Spush(10);
    S.Spush(3);
    S.Spush(5);
    S.Spush(-1);

    int top = S.Spop();
    cout<<top<<endl;
    cout<<S.SminEle()<<endl;
    return 0;
}
