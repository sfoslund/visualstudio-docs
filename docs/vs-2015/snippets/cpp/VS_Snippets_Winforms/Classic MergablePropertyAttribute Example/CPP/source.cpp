

#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>
#using <System.dll>
#using <System.Data.dll>

using namespace System;
using namespace System::Data;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
public ref class Form1: public Form
{
   // <Snippet1>
public:
   [MergableProperty(true)]
   property int MyProperty 
   {
      int get()
      {
         // Insert code here.
         return 0;
      }
      void set( int value )
      {
         // Insert code here.
      }
   }
   // </Snippet1>

   property int MyProperty2 
   {
      int get()
      {
         // <Snippet2>
         // Gets the attributes for the property.
         AttributeCollection^ attributes = TypeDescriptor::GetProperties( this )[ "MyProperty" ]->Attributes;

         // Checks to see if the value of the MergablePropertyAttribute is Yes.
         if ( attributes[ MergablePropertyAttribute::typeid ]->Equals( MergablePropertyAttribute::Yes ) )
         {
            // Insert code here.
         }

         // This is another way to see if the property is bindable.
         MergablePropertyAttribute^ myAttribute = dynamic_cast<MergablePropertyAttribute^>(attributes[ MergablePropertyAttribute::typeid ]);
         if ( myAttribute->AllowMerge )
         {
            // Insert code here.
         }
         // </Snippet2>
         return 0;
      }
   }

   property int MyProperty3 
   {
      int get()
      {
         // <Snippet3>
         AttributeCollection^ attributes = TypeDescriptor::GetAttributes( MyProperty );
         if ( attributes[ MergablePropertyAttribute::typeid ]->Equals( MergablePropertyAttribute::Yes ) )
         {
            // Insert code here.
         }
         // </Snippet3>
         return 0;
      }
   }
};
