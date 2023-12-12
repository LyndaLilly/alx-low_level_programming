int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int mod(int x, int y);

/**
* add - this adds int
* @x: this is the 1st int to add
* @y: this is the 2nd int to add
* Return: sum of int
*/

int add(int x, int y)
{
	return (x + y);
}

/**
* sub - this substract int
* @x: this is 1st int to sub
* @y: this is the 2nd int to sub
* Return: subtract
*/

int sub(int x, int y)
{
	return (x - y);
}

/**
* mul - this multiply int
* @x:  this is 1st int to multiply
* @y: this is 1st int to multiply
* Return: multiple
*/

int mul(int x, int y)
{
	return (x * y);
}

/**
* div - this int to divide
* @x: this is 1st int to divide
* @y: this is 1st int to div
* Return: dividend result
*/

int div(int x, int y)
{
	return (x / y);
}

/**
  mod - this int to modify
  @x: this is 1st int to mod
  @y: this is 1st int to mod
  Return: modulus
*/

int mod(int x, int y)
{
	return (x % y);
}
