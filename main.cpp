
extern void driver_cplus();
extern void driver_block();
extern void driver_rvals();
extern void c11();
extern void c112();
extern void c113();

extern void driver_vector();
extern void driver_list();
extern void driver_deque();
extern void driver_set();
extern void driver_map();
extern void funcobjects();
extern void arrayrefs();

extern void concurrency();
extern void concurrency2();
extern void mythread();
extern void mythread2();
extern void driver_spreadsheet();

extern void driver_classtempl();
extern void driver_functempl();
extern void driver_fact();
extern void driver_special();
extern void driver_partial();

extern void driver_arrays();

extern void driver_extract();

extern void driver_optionals();
extern void driver_stringview();

int main(int argc, char *argv[])
{
    driver_cplus();
    driver_block();
    driver_rvals();
    c11();
    c112();
    c113();

    driver_vector();
    driver_list();
    driver_deque();
    driver_set();
    driver_map();
    funcobjects();

    arrayrefs();
/*
    concurrency();
    concurrency2();
    mythread();
    mythread2();*/

    driver_spreadsheet();
    driver_arrays();


    driver_classtempl();
    driver_functempl();
    driver_fact();
    driver_special();
    driver_partial();

    driver_extract();

    driver_optionals();
    driver_stringview();

    return 0;
}
