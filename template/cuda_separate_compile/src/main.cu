#include <cstdio>

__global__ void child_thread()
{
 printf("inside child thread");
}

__global__ void main_kernel()
{
 printf("inside main thread");
 child_thread<<<1, 1>>>();
}

int main() 
{
 main_kernel<<<1, 1>>>();
}