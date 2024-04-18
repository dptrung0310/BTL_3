Bài 1:
char c = ‘A', d = ‘B';
char* p1 = &c;
char* p2 = &d;
char* p3;
Giả sử địa chỉ của c là 0x1234, địa chỉ của d là 0x5678.
p3 = &d;
cout << “*p3 = “ << *p3 << “, p3 = “ << p3 << endl;
=> Output: *p3 = B, p3 = 0x5678 (địa chỉ của biến d) 
p3 = p1;
cout << “*p3 = “ << *p3 << “, p3 = “ << p3 << endl;
=> Output: *p3 = A, p3 = 0x1234 (địa chỉ của biến c) 
*p1 = *p2;
cout << “*p1 = “ << *p1 << “, p1 = “ << p1 << endl;
=> Output: *p1 = B, p1 = 0x1234 (địa chỉ của biến c) 

Bài 2:
int *p;
int i;
int k;
i = 4;
k = i;
p = &i;
a) k = 5;: Lệnh này gán giá trị 5 cho biến k, không phải biến i. Do đó, giá trị của i không thay đổi từ 4 thành 5.
b) *k = 5;: Trong trường hợp này, k là một biến nguyên (int), không phải con trỏ. Điều này sẽ dẫn đến một lỗi biên dịch vì không thể giải tham chiếu một giá trị nguyên như một con trỏ.
c) p = 5;: Lệnh này cố gắng gán giá trị 5 cho con trỏ p, không phải giá trị của biến mà p đang trỏ tới. Điều này cũng sẽ gây lỗi biên dịch vì 5 không phải là một địa chỉ hợp lệ.
d) *p = 5;: Đây là lệnh sẽ gán giá trị 5 cho biến mà con trỏ p đang trỏ tới. Vì p trỏ tới biến i, nên lệnh này sẽ làm thay đổi giá trị của i từ 4 thành 5.
Do đó, chỉ có lệnh *p = 5; sẽ gán giá trị 5 cho biến i.

Bài 3:
char c = ‘C';
double *p = &c;
Đoạn code trên lỗi vì:
Cố gắng gán địa chỉ của một biến kiểu char (c) vào một con trỏ kiểu double (p). 
Điều này là không hợp lệ vì kiểu dữ liệu của con trỏ và biến không khớp nhau.
Biến c có kiểu dữ liệu là char, có kích thước bộ nhớ nhỏ hơn so với kiểu dữ liệu của con trỏ double. 
Khi gán địa chỉ của biến c cho con trỏ p, có một sự không phù hợp về kích thước dữ liệu, vì con trỏ double cần một địa chỉ dài hơn để lưu trữ một giá trị double hợp lệ.