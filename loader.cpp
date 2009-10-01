extern start_ctors, end_ctors, start_dtors, end_dtors;
  
extern "C"
void
loader (void)
{
    for (unsigned long* call = &start_ctors; call < &end_ctors; call++) {
        ((void (*)(void))* call)();
    }

    main();

    for (unsigned long* call = &start_dtors; call < &end_dtors; call++) {
        ((void (*)(void))* call)();
    }
}

