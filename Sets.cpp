#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
class MySet
{
    private:
        T *elements;
        int cardinality;
    public:
        // Constructor to initialise the instance variables
        MySet(int size = 0)
        {
            cardinality = size;
            elements = new T[size];
        }
        // Function to take input of elements and removing duplicates in the set
        void takeElements()
        {
            for(int index = 0; index < cardinality; ++index)
                cin >> elements[index];
            removeDuplicates();
        }
        // Function to display the set in the readable format
        void display()
        {
            cout << "{ ";
            for(int index = 0; index < cardinality; ++index)
            {
                cout << elements[index];
                if(index != cardinality - 1)
                    cout << ", ";
                else
                    cout << " ";
            } 
            cout << "}" << endl;
        }
        // Function to remove duplicates in the set
        void removeDuplicates()
        {
            for(int index = 0; index < cardinality; ++index)
                for(int check = index + 1; check < cardinality; ++check)
                    if(elements[index] == elements[check])
                    {
                        for(int del = check; del < cardinality; ++del)
                            elements[del] = elements[del+1];
                        cardinality--;
                        check--;
                    }
        }
        // Overloading + operator to find the union of two sets
        MySet operator+ (const MySet obj)
        {
            MySet temp(cardinality + obj.cardinality);
            int index = 0;
            for(int copy = 0; copy < cardinality; ++copy)
                temp.elements[index++] = elements[copy];
            for(int copy = 0; copy < obj.cardinality; ++copy)
                temp.elements[index++] = obj.elements[copy];
            temp.removeDuplicates();
            return temp;
        }
        // Overloading * operator to find the intersection of two sets
        MySet operator* (const MySet obj)
        {
            int count = 0;
            for(int index = 0; index < cardinality; ++index)
                for(int check = 0; check < obj.cardinality; ++check)
                    if(elements[index] == obj.elements[check])
                        count++;
            MySet temp(count);
            count = 0;
            for(int index = 0; index < cardinality; ++index)
                for(int check = 0; check < obj.cardinality; ++check)
                    if(elements[index] == obj.elements[check])
                        temp.elements[count++] = elements[index];
            return temp;
        }
        // Overloading - operator to find the difference between two sets
        MySet operator- (const MySet obj)
        {
            int count = 0;
            for(int index = 0; index < cardinality; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.cardinality; ++check)
                    if(elements[index] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            MySet temp(count);
            int temp_index = 0;
            for(int index = 0; index < cardinality; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.cardinality; ++check)
                    if(elements[index] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.elements[temp_index++] = elements[index];
            }
            return temp;
        }
        // Overloading ^ operator to find the symmetric difference between two sets
        MySet operator^ (const MySet obj)
        {
            int count = 0;
            for(int index = 0; index < cardinality; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.cardinality; ++check)
                    if(elements[index] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            for(int index = 0; index < obj.cardinality; ++index)
            {
                int flag = 0;
                for(int check = 0; check < cardinality; ++check)
                    if(obj.elements[index] == elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            MySet temp(count);
            count = 0;
            for(int index = 0; index < cardinality; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.cardinality; ++check)
                    if(elements[index] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.elements[count++] = elements[index];
            }
            for(int index = 0; index < obj.cardinality; ++index)
            {
                int flag = 0;
                for(int check = 0; check < cardinality; ++check)
                    if(obj.elements[index] == elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.elements[count++] = obj.elements[index];
            }
            return temp;
        }
        // Overloading = operator to assign the values of one set into another
        MySet operator= (const MySet obj)
        {
            MySet temp(obj.cardinality);
            for(int index = 0; index < cardinality; ++index)
                temp.elements[index] = obj.elements[index];
            return temp;
        }
        // Overloading == operator to check if two sets are equal or not
        bool operator== (const MySet obj)
        {
            if(cardinality != obj.cardinality)
                return false;
            else
            {
                int flag = 0;
                for(int index = 0; index < cardinality; ++index)
                    for(int check = 0; check < obj.cardinality; ++check)
                        if(elements[index] == obj.elements[check])
                            flag++;
                if(flag == cardinality)
                    return true;
                else
                    return false;
            }
        }
        // Function to print the cardinality of a set
        void printCardinality()
        {
            cout << cardinality;
        }
        // Function to print the power set of a given set
        void powerSet()
        {
            int powerset_size = pow(2, cardinality);
            for(int counter = 0; counter < powerset_size; ++counter)
            {
                int count_elements = 0;
                cout << "{ ";
                for(int set = 0; set < cardinality; ++set)
                    if(counter & (1 << set))
                    {
                        if(count_elements != 0)
                            cout << ", ";
                        cout << elements[set];
                        count_elements++;
                    }
                cout << " }";
                if(counter != powerset_size - 1)
                    cout << ", ";
            }
        }
};

//Function to print all the sets
template <typename T>
void printSets(MySet <T> firstSet, MySet <T> secondSet, MySet <T> thirdSet, MySet <T> fourthSet, MySet <T> fifthSet, MySet <T> sixthSet, bool answer)
{
    system("cls");
    cout << "Set A: ";
    firstSet.display();
    cout << "\nSet B: ";
    secondSet.display();
    cout << "\nUnion: ";
    thirdSet.display();
    cout << "\nIntersection: ";
    fourthSet.display();
    cout << "\nDifference: ";
    fifthSet.display();
    cout << "\nSymmetric Difference: ";
    sixthSet.display();
    cout << "\nPower Set of A... \n{ ";
    firstSet.powerSet();
    cout << " }\n";
    cout << "\nPower Set of B... \n{ ";
    secondSet.powerSet();
    cout << " }\n";
    if(answer == true)
        cout << "\nEquality: The Sets A and B are equal\n\n";
    else
        cout << "\nEquality: The Sets A and B are not equal\n\n";
}

int main()
{
    int choice_type = 0;
    char choice_iterate = 'N';
    do
    {
        system("cls");
        cout << "*****Menu*****\n";
        cout << "Choose the type of data in the set...\n";
        cout << "1. Integer\n";
        cout << "2. String\n";
        cout << "3. Floating-points\n";
        cout << "Enter your choice: ";
        cin >> choice_type;
        system("cls");
        switch(choice_type)
        {
            case 1: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <int> firstSet(size_of_1Set);
                        cout << "Enter the elements of 1st Set...\n";
                        firstSet.takeElements();
                        MySet <int> secondSet(size_of_2Set);
                        cout << "Enter the elements of 2nd Set...\n";
                        secondSet.takeElements();
                        MySet <int> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <int> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <int> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <int> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            case 2: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <char> firstSet(size_of_1Set);
                        cout << "Enter the elements of 1st Set...\n";
                        firstSet.takeElements();
                        MySet <char> secondSet(size_of_2Set);
                        cout << "Enter the elements of 2nd Set...\n";
                        secondSet.takeElements();
                        MySet <char> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <char> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <char> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <char> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            case 3: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <float> firstSet(size_of_1Set);
                        cout << "Enter the elements of 1st Set...\n";
                        firstSet.takeElements();
                        MySet <float> secondSet(size_of_2Set);
                        cout << "Enter the elements of 2nd Set...\n";
                        secondSet.takeElements();
                        MySet <float> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <float> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <float> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <float> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            default: cout << "Wrong choice of Options!!!";
        }
        cout << "Do you want to operate more (Y/N): ";
        cin >> choice_iterate;
        system("cls");
    } while (choice_iterate == 'Y' || choice_iterate == 'y');
    return 0;
}