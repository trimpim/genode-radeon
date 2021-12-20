 #include <base/component.h>

//#include <lx_emul/initcall_order.h>


 void Component::construct(Genode::Env &env)
 {
     env.exec_static_constructors();
     /* iterate through the list of initcalls and call them in order */
 }

