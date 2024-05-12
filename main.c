#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
typedef struct products products;
typedef struct categories categories;
typedef struct supermarket supermarket;

struct products // struct for product to display its information
{
    char name[30];
    int quantity;
    int price;
};
struct categories // struct for cat to display its information
{
    char name[30];
    products product[30];
    int productCount;
};
struct supermarket // struct for supermarket to display its information(cat and product)
{
    categories category [30];
    int categoryCount;
};

void intialSuper(supermarket *supermarket) // if i didn't add any cat and product display this intial cat and products
{
    supermarket->categoryCount=2;

    for(int i=0; i<2; i++)
    {
        supermarket->category[i].productCount=2;
    }
    //ÚãáÊ Çæá 2 ßÇÊíÌæÑíÒ
    strcpy(supermarket->category[0].name,"juices");
    strcpy(supermarket->category[1].name,"chips");

    // ÓãíÊ Çæá 2 ÈÑæÏÇßÊ Ýí Çæá ßÇÊíÌæÑí
    strcpy(supermarket->category[0].product[0].name,"Bety");
    strcpy(supermarket->category[0].product[1].name,"Juhayna");

    //ÖÝÊ ÇáßæÇäÊÊí  ááÈÑæÏÇßÊÓ ÈÊÇÚÉ Çæá ßÇÊ
    supermarket->category[0].product[0].quantity = 12;
    supermarket->category[0].product[1].quantity = 13;
    // ÖÝÊ ÓÚÑ ááÈÑæÏÇßÊÓ Çæá ßáÊ
    supermarket->category[0].product[0].price = 6;
    supermarket->category[0].product[1].price = 8;

    strcpy(supermarket->category[1].product[0].name,"chipsy");
    strcpy(supermarket->category[1].product[1].name,"tiger");

    supermarket->category[1].product[0].quantity = 12;
    supermarket->category[1].product[1].quantity = 13;

    supermarket->category[1].product[0].price = 6;
    supermarket->category[1].product[1].price = 8;


}
void Display(supermarket *supermarket)
{
    SetColor(11);
    printf("Our Avaliable product:\n \n");
    SetColor(15);
    for(int i =0; i<supermarket->categoryCount; i++)
    {
        // SetColor(18);
        printf("Our Own Category: %s\n \n",supermarket->category[i].name);
        //SetColor(18);
        for(int j =0; j<supermarket->category[i].productCount; j++)
        {
            //SetColor(19);
            printf("\tProduct Name: %s | Quantity: %d | Price: %d\n \n",
                   supermarket->category[i].product[j].name,
                   supermarket->category[i].product[j].quantity,
                   supermarket->category[i].product[j].price);
        }
    }

}

void addCategory(supermarket *supermarket)
{
    char ch;

    do
    {
        if (supermarket->categoryCount < 30)
        {
            printf("Please Enter The Category Name: \n");
            char catName[20];
            scanf("%s",catName);

            //////////////////////

            int findCatIndex=-1;
            for(int i=0; i<supermarket->categoryCount; i++)
            {
                if(strcmp(supermarket->category[i].name, catName) == 0)
                {
                    findCatIndex=i;
                    break;
                }
            }
            if(findCatIndex!=-1)
            {

                printf("this category is found please enter another one \n");
            }
            else
            {
                strcpy(supermarket->category[supermarket->categoryCount].name,catName);
                getchar(); // Clear input buffer

                // Not a garbage value
                supermarket->category[supermarket->categoryCount].productCount = 0;
                supermarket->categoryCount++;

                printf("You added successfully.\n");
            }
            //////////////////

        }
        else
        {
            printf("You Can't Add More Categories.\n");
        }

        printf("Do You Want To Add More Categories? (Y/N): ");
        scanf(" %c", &ch); // Add a space before %c to consume newline character

    }
    while (ch == 'Y' || ch == 'y');


}
void removeCategory(supermarket *supermarket)
{
    char ch;
    do{
    //char catName;
    if(supermarket->categoryCount>0)
    {
        char catName[30];
        printf("Enter Which Category You Want To ReMove: \n");
        scanf("%s",catName);
        int findCatIndex=-1;
        for(int i=0; i<supermarket->categoryCount; i++)
        {
            if(strcmp(supermarket->category[i].name, catName) == 0)
            {
                findCatIndex=i;
                break;
            }
        }
        if(findCatIndex!=-1)
        {
            for(int i =findCatIndex; i<supermarket->categoryCount-1; i++)
            {
                supermarket->category[i]=supermarket->category[i+1];

            }
            supermarket->categoryCount--;
            printf("you Remove sucessfully \n");
        }
          else
    {
        printf("there is no category to remove \n ");
    }
    }
    else
        {
            printf("There are no categories to remove.\n");
        }

    printf("Do You Want To Add More cat? (Y/N): ");
        scanf(" %c", &ch);
    }while (ch == 'Y' || ch == 'y');

}
void addProduct(supermarket *supermarket)
{
    char ch;
    char pName[30];
    char catName[30];
    int pprice;
    int pquantity;
    do
    {
        printf("Please Enter Product Name: \n");
        scanf("%s",pName);
        printf("Please Enter Category Name that you want to put this product on it : \n");
        scanf("%s",catName);

        int findCatIndex=-1;
        for(int i=0; i<supermarket->categoryCount; i++)
        {
            if(strcmp(supermarket->category[i].name,catName)==0)
            {
                findCatIndex=i;
                break;
            }
        }
        if(findCatIndex!=-1)
        {
            int findPInde=-1;
            for(int i=0; i<supermarket->category[findCatIndex].productCount; i++)
            {
                if(strcmp(supermarket->category[findCatIndex].product[i].name,pName)==0)
                {
                    findPInde=i;
                    break;
                }
            }


            if(findPInde!=-1)
            {
                printf("This product is found in this category already\n ");
            }
            else
            {
                strcpy(supermarket->category[findCatIndex].product[supermarket->category[findCatIndex].productCount].name,pName);



                printf("Please Enter The Quantity: \n");

                scanf("%d",&pquantity);
                printf("Please Enter The Price: \n");
                scanf("%d",&pprice);
                supermarket->category[findCatIndex].product[supermarket->category[findCatIndex].productCount].quantity = pquantity;
                supermarket->category[findCatIndex].product[supermarket->category[findCatIndex].productCount].price = pprice;



                supermarket->category[findCatIndex].productCount++;
            }



        }
        else
            {
                printf("This Category is not found \n");
            }


        printf("Do You Want To Add More Products? (Y/N): ");
        scanf(" %c", &ch);
    }
    while (ch == 'Y' || ch == 'y');

}
void removeProduct(supermarket *supermarket)
{
    char pName[30];
    char catName[30];
    char ch;
    do
    {
        printf("Please Enter Product Name: \n");
        scanf("%s",pName);
        printf("Please Enter Category Name that you want to removes this product from it : \n");
        scanf("%s",catName);

        int findCatIndex=-1;
        for(int i=0; i<supermarket->categoryCount; i++)
        {
            if(strcmp(supermarket->category[i].name,catName)==0)
            {
                findCatIndex=i;
                break;
            }
        }
        //int findPIndex=-1;
        if(findCatIndex!=-1)
        {
            int findPIndex = -1;

            for (int i = 0; i < supermarket->category[findCatIndex].productCount; i++)
            {
                if (strcmp(supermarket->category[findCatIndex].product[i].name, pName) == 0)
                {
                    findPIndex = i;
                    break;
                }
            }
            if (findPIndex != -1)
            {
                for (int i = findPIndex; i < supermarket->category[findCatIndex].productCount - 1; i++)
                {
                    supermarket->category[findCatIndex].product[i] = supermarket->category[findCatIndex].product[i + 1];
                }
                supermarket->category[findCatIndex].productCount--;
                printf("Product removed successfully.\n");
            }
            else
            {
                printf("This Product does not exist in the category.\n");
            }
        }
        else
        {
            printf("This Category is not found \n");
        }



        printf("Do You Want To Remove More products? (Y/N): ");
        scanf(" %c", &ch);

    }
    while (ch == 'Y' || ch == 'y');

}
void buy(supermarket *supermarket)
{
    char pName[30];
    char catName[30];
    int quantity;
    char ch;
    do
    {
        printf("Please Enter Product Name: \n");
        scanf("%s",pName);
        printf("Please Enter Category Name  : \n");
        scanf("%s",catName);

        int findCatIndex=-1;
        for(int i=0; i<supermarket->categoryCount; i++)
        {
            if(strcmp(supermarket->category[i].name,catName)==0)
            {
                findCatIndex=i;
                break;
            }
        }
        int findPIndex=-1;
        for(int i=0; i<supermarket->category[findCatIndex].productCount; i++)
        {
            if(strcmp(supermarket->category[findCatIndex].product[i].name,pName)==0)
            {
                findPIndex=i;
                break;
            }
        }
        if(findPIndex!=-1)
        {
            printf("Please Enter The Quantity: \n");
            scanf("%d",&quantity);

            //supermarket->category[i]=supermarket->category[i+1];
            //supermarket->category[findCatIndex].product[i]=supermarket->category[findCatIndex].product[i+1];
            if(quantity <= supermarket->category[findCatIndex].product[findPIndex].quantity)
            {
                supermarket->category[findCatIndex].product[findPIndex].quantity-=quantity;

                printf("You Buy it sucesfully ! \n");
            }
            else
            {
                printf("You Don't have this amount of quantity \n ");
            }

        }
        else
        {
            printf("this is not exist");
        }

        printf("Do You Want To add More Products? (Y/N): ");
        scanf(" %c", &ch);

    }
    while (ch == 'Y' || ch == 'y');
}
void moveProduct(supermarket *supermarket)
{
    char pName[30];
    char destinationName[30];
    char sourceName[30];
    char ch;

    do
    {
        int sourceIndex = -1;
        printf("Enter Source Category Name: ");
        scanf("%s", sourceName);


        for (int i = 0; i < supermarket->categoryCount; i++)
        {
            if (strcmp(supermarket->category[i].name, sourceName) == 0)
            {
                sourceIndex = i;
                break;
            }
        }

        if (sourceIndex != -1)
        {
            printf("Enter Product Name: ");
            scanf("%s", pName);

            int pIndex = -1;

            for (int i = 0; i < supermarket->category[sourceIndex].productCount; i++)
            {
                if (strcmp(supermarket->category[sourceIndex].product[i].name, pName) == 0)
                {
                    pIndex = i;
                    break;
                }
            }

            if (pIndex != -1)
            {
                printf("Enter Destination Category: ");
                scanf("%s", destinationName);

                int destinationIndex = -1;

                for (int i = 0; i < supermarket->categoryCount; i++)
                {
                    if (strcmp(supermarket->category[i].name, destinationName) == 0)
                    {
                        destinationIndex = i;
                        break;
                    }
                }

                if (destinationIndex != -1)
                {

                    supermarket->category[destinationIndex].product[supermarket->category[destinationIndex].productCount] =
                        supermarket->category[sourceIndex].product[pIndex];

                    supermarket->category[destinationIndex].productCount++;
                    for(int i =pIndex; i<supermarket->category[sourceIndex].productCount; i++)
                    {
                        //supermarket->category[i]=supermarket->category[i+1];
                        supermarket->category[sourceIndex].product[i]=supermarket->category[sourceIndex].product[i+1];
                         //supermarket->category[sourceIndex].productCount--;
                    }

                    supermarket->category[sourceIndex].productCount--;

                    printf("Product moved successfully!\n");
                }
                else
                {
                    printf("Destination category not found.\n");
                }
            }
            else
            {
                printf("Product not found in the source category.\n");
            }
        }
        else
        {
            printf("Source category not found.\n");
        }

        printf("Do you want to move more products? (Y/N): ");
        scanf(" %c", &ch);

    }
    while (ch == 'Y' || ch == 'y');
}
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int main()

{
    struct supermarket super;
    intialSuper(&super);


    int selectedOption=0;
    while(1)
    {

        system("cls");
        SetColor(0x0E);
        printf("\t \t \t  Our SuperMarket");
        SetColor(15);
        gotoxy(5,3);
        if(selectedOption ==0)
        {
            SetColor(0x0E);
            printf("\t \t -->Display");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Display");
        }
        gotoxy(5,4);
        if(selectedOption ==1)
        {
            SetColor(0x0E);
            printf("\t \t -->Add Category");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Add Category");
        }
        gotoxy(5,5);
        if(selectedOption ==2)
        {
            SetColor(0x0E);
            printf("\t \t -->Remove Category");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Remove Category");
        }
        gotoxy(5,6);
        if(selectedOption ==3)
        {
            SetColor(0x0E);
            printf("\t \t-->Add Product");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Add product");
        }
        gotoxy(5,7);
        if(selectedOption ==4)
        {
            SetColor(0x0E);
            printf("\t \t -->Remove product");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Remove product");
        }
        gotoxy(5,8);
        if(selectedOption ==5)
        {
            SetColor(0x0E);
            printf("\t \t -->Move Product From Category To Another");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Move Product From Category To Another");
        }
        gotoxy(5,9);
        if(selectedOption ==6)
        {
            SetColor(0x0E);
            printf("\t \t -->Buy");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Buy");
        }
        gotoxy(5,10);
        if(selectedOption ==7)
        {
            SetColor(0x0E);
            printf("\t \t -->Exit");
        }
        else
        {
            SetColor(0x0F);
            printf("\t \t Exit");
        }
        char key =_getch();
        switch(key)
        {



        case 72:
            if(selectedOption==0)
            {
                selectedOption=7;
            }
            else
            {
                selectedOption--;
            }
            break;
        case 80:
            if(selectedOption==7)
            {
                selectedOption=0;
            }
            else
            {
                selectedOption++;
            }
            break;

        case 13:
            switch(selectedOption)
            {


            case 0:
                system("cls");
                Display(&super);
                _getch();
                break;
            case 1:
                system("cls");
                Display(&super);
                addCategory(&super);
                //_getch();
                break;
            case 2:
                system("cls");
                Display(&super);
                removeCategory(&super);
                //_getch();
                break;
            case 3:
                system("cls");
                Display(&super);
                addProduct(&super);
                //_getch();
                break;
            case 4:
                system("cls");
                Display(&super);
                removeProduct(&super);
                //_getch();
                break;
            case 5:
                system("cls");
                Display(&super);
                moveProduct(&super);
                //_getch();
                break;
            case 6:
                system("cls");
                Display(&super);
                buy(&super);
                //_getch();
                break;
            case 7:
                system("cls");
                return 0;
                break;
            }


        }
    }
    return 0;
}
