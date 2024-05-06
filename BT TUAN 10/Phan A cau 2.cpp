 int* p = new int; 
 int* p2 = p;
 *p = 10;
 delete p; //Dòng này giải phóng bộ nhớ được cấp phát cho p. Tuy nhiên, sau khi giải phóng, p2 vẫn trỏ đến vùng nhớ đã bị giải phóng. Điều này gây lỗi undefined behavior.
*p2 = 100;//Dòng này gán giá trị 100 vào vùng nhớ mà p2 trỏ đến. Vùng nhớ này đã bị giải phóng, nên đây là lỗi undefined behavior.
 cout << *p2;//Dòng này in ra giá trị tại vùng nhớ mà p2 trỏ đến. Vì vùng nhớ này đã bị giải phóng, nên đây là lỗi undefined behavior.
 delete p2;//Dòng này giải phóng bộ nhớ được cấp phát cho p2. Tuy nhiên, vùng nhớ này đã bị giải phóng trước đó, nên đây là lỗi undefined behavior.
