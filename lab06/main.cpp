#include <iostream>
#include "unsortedtype.cpp"
using namespace std;

int main()
{
    UnsortedType<int> list1;
    UnsortedType<int> list2;
    UnsortedType<int> combinedList;

    int sizeList1, sizeList2;

    sizeList1 = 10;
    list1.InsertItem(1);
    list1.InsertItem(5);
    list1.InsertItem(6);
    list1.InsertItem(10);
    list1.InsertItem(14);
    list1.InsertItem(20);
    list1.InsertItem(25);
    list1.InsertItem(31);
    list1.InsertItem(38);
    list1.InsertItem(40);

    sizeList2 = 12;
    list2.InsertItem(2);
    list2.InsertItem(4);
    list2.InsertItem(7);
    list2.InsertItem(9);
    list2.InsertItem(16);
    list2.InsertItem(19);
    list2.InsertItem(23);
    list2.InsertItem(24);
    list2.InsertItem(32);
    list2.InsertItem(35);
    list2.InsertItem(36);
    list2.InsertItem(42);



    // Printing List 1 and List 2

    // List 1
    int temp;
    for(int i=0; i<sizeList1; i++)
    {
        list1.GetNextItem(temp);
        cout << temp << "\t";
    }
    cout << endl;
    list1.ResetList();

    // List 2
    for(int i=0; i<sizeList2; i++)
    {
        list2.GetNextItem(temp);
        cout << temp << "\t";
    }
    cout << endl << endl << endl;
    list2.ResetList();



    // Merging Two Lists

    int itemList1, itemList2;

    list1.GetNextItem(itemList1);
    list2.GetNextItem(itemList2);

    // Comparing two values and inserting the greater one to the combined list.
    // This comparison will go on until any of the lists is empty.

    //int loopCount = 0;
    while(list1.LengthIs() != 0 && list2.LengthIs() != 0)
    {
        if(itemList1 > itemList2)
        {
            combinedList.InsertItem(itemList1);
            if(list1.LengthIs() != 1)
            {
                list1.GetNextItem(temp);
                list1.DeleteItem(itemList1);
                itemList1 = temp;
            }else
            {
                list1.DeleteItem(itemList1);
                list1.ResetList();
            }
        }else if(itemList1 < itemList2)
        {
            combinedList.InsertItem(itemList2);
            if(list2.LengthIs() != 1)
            {
                list2.GetNextItem(temp);
                list2.DeleteItem(itemList2);
                itemList2 = temp;
            }else
            {
                list2.DeleteItem(itemList2);
                list2.ResetList();
            }
        }
        //loopCount++;
    }

    // If List 1 is not empty yet,
    // Insert the remaining items of List 1 to the combined list
    if(list1.LengthIs() != 0)
    {
        while(list1.LengthIs() != 0)
        {
            combinedList.InsertItem(itemList1);
            if(list1.LengthIs() != 1)
            {
                list1.GetNextItem(temp);
                list1.DeleteItem(itemList1);
                itemList1 = temp;
            }else
            {
                list1.DeleteItem(itemList1);
                list1.ResetList();
            }
            //loopCount++;
        }
    }
    // OR, If List 2 is not empty yet,
    // Insert the remaining items of List 2 to the combined list
    else if(list2.LengthIs() != 0)
    {
        while(list2.LengthIs() != 0)
        {
            combinedList.InsertItem(itemList2);
            if(list2.LengthIs() != 1)
            {
                list2.GetNextItem(temp);
                list2.DeleteItem(itemList2);
                itemList2 = temp;
            }else
            {
                list2.DeleteItem(itemList2);
                list2.ResetList();
            }
            //loopCount++;
        }
    }
    //cout << loopCount << endl;



    // Print the combined list

    //cout << combinedList.LengthIs() << endl;
    for(int i=0; i<combinedList.LengthIs(); i++)
    {
        combinedList.GetNextItem(temp);
        cout << temp << "\t";
    }
    cout << endl;
    combinedList.ResetList();


    return 0;
}
