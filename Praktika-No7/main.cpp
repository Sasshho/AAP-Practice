#include<iostream>
#include<exception>
#include<stdexcept>

void FillMatrix(int ** matrix,int rows,int cols)
{
for(size_t i =0;i<rows;i++)
{
for(size_t j=0;j<cols;j++)
{
std::cout<<"Enter number in row: "<<i+1<<", column: "<<j+1<<" - ";
if(!(std::cin>>matrix[i][j]))
{
throw std::invalid_argument("Invalid argument");
}
}
}
}

void PrintTransposedMatrix(int ** matrix,int rows,int cols)
{


for(size_t i =0;i<cols;i++)
{
for(size_t j=0;j<rows;j++)
{
std::cout<<matrix[j][i];
}
std::cout<<"\n";
}
}




int main()
{
int rows=1;
int cols=1;


try
{
std::cout<<"Enter number of rows : ";
if(!(std::cin>>rows)){throw std::invalid_argument("Invalid argument");}

std::cout<<"Enter number of columns : ";
if(!(std::cin>>cols)){throw std::invalid_argument("Invalid argument");}

if(rows==0||cols==0){throw std::invalid_argument("Invalid argument");}
}
catch(const std::invalid_argument& a)
{
std::cerr<<"Error code 1"<<std::endl;
return 1;
}


int ** matrix=new int*[rows];
for(size_t i =0;i<rows;i++)
{
matrix[i]=new int[cols];
}

try
{
FillMatrix(matrix,rows,cols);
}
catch(const std::bad_alloc& a)
{
std::cerr<<"Error code 2"<<std::endl;
return 2;
}
catch(const std::invalid_argument& a)
{
std::cerr<<"Error code 1"<<std::endl;
return 1;
}

PrintTransposedMatrix(matrix,rows,cols);
return 0;
}
