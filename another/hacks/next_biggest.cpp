/**
 * Вычисление следующего большего числа с тем же количеством единичных битов
 */
unsigned snoob(unsigned x) 
{
  unsigned smallest, ripple, ones; 
  //-----------------------Пусть x = ***0 1111 0000
  smallest = x & -x;  //-------------0000 0001 0000
  ripple = x + smallest; //----------***1 0000 0000
  ones = x ^ ripple; //--------------0001 1111 0000
  ones = (ones >> 2) / smallest; //--0000 0000 0111
  return ripple | ones; //-----------***1 0000 0111
}
