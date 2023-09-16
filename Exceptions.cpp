#include <iostream>
#include<exception>
using namespace std;

float Divide(float a, float b)//void
{

    //exception ex("Can`t divide by zero");
    float res = 0;
    if (b == 0)
    {
        //cout << "Can`t divide by zero" << endl;//
        throw "Can`t divide by zero";
    }
    if (b == 1)
    {
        throw 404;
    }
    if (b == 2)
    {
        throw exception("Can`t divide by zero");
    }
    else
    {

    res = a / b;
    }
    cout << "res : " << res << endl;
    cout << "Loading...... " << endl;
    return res;
}

class PasswordInvalidException : public exception
{
public:
    PasswordInvalidException(const char * message):exception(message){}
};

class passwordShortException : public exception
{
    int length;
public:
    passwordShortException(const char* message, int length):length(length), exception(message){}
    void Message()
    {
        cout << what() << endl;
        cout << "Real length of pass is " << length << endl;
    }
};
void Login(const char* login, const char* pass)
{
    if (strlen(pass) < 8)
    {
        throw passwordShortException("Pass is to short",strlen(pass));//cout
    }
    if (!isalpha(pass[0]) || !islower(pass[0]))
    {
        throw PasswordInvalidException("Invalis pass ");//later
    }
    if (!isalpha(login[0]) || !isupper(login[0]))
    {
        throw "Login is invalid";//exception()
    }
    
}

class Array
{
    int size;
    int* arr;
public:
    Array(int size =10):size(size)
    {
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = rand() % 50;
        }
    }

    void Print()const
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
    int& operator[](int index)//without &
    {
        if(index >=0 && index <size)
        {
            return arr[index];
        }
        else
        {
            throw out_of_range("Error index ");
            //cout << "Error index " << endl;
        }
    }
    void CheckSize(int size)
    {
        if (size < 0)
        {
            throw length_error("Negative size can`t to be use ...");
           // cout << "Negative size can`t to be use ..." << endl;
        }
        else
        {
            cout << "Size is valid" << endl;
        }
    }
    void SetSize(int newSize)
    {
        if (newSize <= 0)
        {
            throw invalid_argument("New size is can`t to be use ....");
            //cout << "New size can`t to be use ..." << endl;
        }
        else
        {
            int* new_arr = new int[newSize];
            for (size_t i = 0;i<size, i < newSize; i++)
            {
                new_arr[i] = arr[i];
            }
            delete[]arr;
            arr = new_arr;
            size = newSize;
        }
    }
    ~Array()
    {
        delete[]arr;
    }
};



int main()
{
    Array arr(5);
    arr.Print();
    arr[2] = 777;
    arr.Print();
    try
    {
        arr[100] = 777;
        arr.Print();

    }
    catch (const out_of_range& ex)
    {
        cout << ex.what() << endl;
    }
    catch (const length_error& ex)
    {
        cout << ex.what() << endl;
    }
    try
    {
        arr.CheckSize(-1);
    }
    catch (const logic_error& ex)
    {
        cout << ex.what() << endl;
    }
    try
    {
        arr.SetSize(-10);

    }
    catch (const invalid_argument&ex)
    {
        cout << ex.what() << endl;
    }


    //char login[100];
    //char pass[100];
    //for (size_t i = 0; i < 5; i++)
    //{
    //    cout << "Enter login : " << endl;
    //    cin >> login;
    //    cout << "Enter password : " << endl;
    //    cin >> pass;
    //    try
    //    {
    //        Login(login, pass);
    //    }
    //    catch (const char*ex)
    //    {
    //        cout << ex << endl;
    //    }
    //    catch (const exception& ex)//перенести в кінець
    //    {
    //        cout << ex.what() << endl;
    //    }
    //    catch (PasswordInvalidException& ex)
    //    {
    //        cout << ex.what() << endl;
    //        cout << "u can use A-Z, a-z, 0-9" << endl;
    //    }
    //    catch (passwordShortException& ex)
    //    {
    //        cout << "To short pass " << endl;
    //        ex.Message();
    //        cout << "Length must be more than 8" << endl;
    //    }
    //}




    //int a, b;
    //cout << "Enter numbers a & b : " << endl;
    //cin >> a >> b;
    ////Divide(a, b);
    //
    //try
    //{
    //    cout << "res : " << Divide(a, b) << endl;
    //}
    //catch (const char * ex)
    //{
    //    cout << ex << endl;
    //}
    //catch (const int ex)
    //{
    //    cout << ex << endl;
    //}
    //catch (const exception& ex)
    //{
    //    cout << ex.what() << endl;
    //}
    //catch (...)
    //{
    //    cout << "Unknown exception" << endl;
    //}
    //cout << "Continue ..." << endl;
}
