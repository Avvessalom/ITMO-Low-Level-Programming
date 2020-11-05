#include <stdio.h>
#include "linked_list.h"
#include "higher_ord_func.h"
#include "list_io.h"

void print_val(value a){
    printf("%d\n", a);
}

void print_val_whitespace(value a){
    printf("%d ", a);
}

value sqr(value v){
    return v * v;
}

value cbr(value v){
    return v * v * v;
}

value abs(value v){
    return v > 0 ? v : -v;
}

value times_2(value v){
    return v * 2;
}

int main() {
    
    // PART 1 - PAGE 197
    
    linked_list list_1 = read_from_console();
    
    puts("Ваш массив:");
    print_list(list_1);
    
    puts("Сумма элементов массива:");
    print_val(list_sum(list_1));
    
    list_free(list_1);
    
    // PART 2 - PAGE 218
    
    linked_list list_2 = read_from_console();
    
    puts("Ваш массив:");
    print_list(list_2);
    
    puts("Напечатанный с помощью FOREACH ' ':");
    foreach(list_2, &print_val_whitespace);
    puts("");
    
    puts("Напечатанный с помощью FOREACH '\\n':");
    foreach(list_2, &print_val);
    
    puts("Квадраты элементов:");
    linked_list list_2_sqr = map(list_2, &sqr);
    print_list(list_2_sqr);
    
    puts("Кубы элементов:");
    linked_list list_2_cbr = map(list_2, &cbr);
    print_list(list_2_cbr);
    
    puts("Модули элементов:");
    map_mut(list_2, &abs);
    print_list(list_2);
    
    puts("Степени двойки:");
    linked_list twos = unfold_l(1, 10, &times_2);
    print_list(twos);
    
    puts("Запись массива в файл (TEXT)...");
    const char* file_text = "saved.txt";
    save(list_2, file_text);
    linked_list read_text_list;
    load(&read_text_list, file_text);
    puts("Чтение массива обратно:");
    print_list(read_text_list);
    
    puts("Запись массива в файл (BIN)...");
    const char* file_bin = "saved.bin";
    serialize(list_2, file_bin);
    linked_list read_bin_list;
    deserialize(&read_bin_list, file_bin);
    puts("Чтение массива обратно:");
    print_list(read_bin_list);
    
    list_free(list_2);
    list_free(list_2_sqr);
    list_free(list_2_cbr);
    list_free(twos);
    list_free(read_text_list);
    list_free(read_bin_list);
    
    puts("Память очищена");
}


	
