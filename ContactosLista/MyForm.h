#pragma once
#include <msclr/marshal_cppstd.h>

void quickSort(std::string* arr, int start, int end) {
	int size = end - start + 1;
	if (size < 2) {
		return;
	}
	int index = start;
	std::string pivot = arr[end];
	for (int i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[index]);
			index++;
		}
	}
	swap(arr[end], arr[index]);
	if (index > start) {
		quickSort(arr, start, index - 1);
	}
	if (index < end) {
		quickSort(arr, index + 1, end);
	}
}
namespace ContactosLista {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->listBox3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->listBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->listBox1, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(35, 37);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(796, 322);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"4", L"3", L"2", L"1", L"0" });
			this->listBox3->Location = System::Drawing::Point(400, 23);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(393, 292);
			this->listBox3->TabIndex = 5;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0", L"1", L"2", L"7", L"4" });
			this->listBox2->Location = System::Drawing::Point(281, 23);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(113, 292);
			this->listBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(400, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Correo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(281, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Teléfono";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Persona7", L"Persona4", L"Persona3", L"Persona2",
					L"Persona0"
			});
			this->listBox1->Location = System::Drawing::Point(3, 23);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(272, 292);
			this->listBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 377);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Agregar contacto";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(349, 377);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 30);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Ordenar por teléfono";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(675, 377);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 30);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Ordenar por nombre";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(861, 508);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Contactos";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Agg contacto
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//Ord por tlfno
	// Fill the namevs array with items from listBox1
	array<String^>^ names = gcnew array<String^>(listBox2->Items->Count);
	for (int i = 0; i < listBox2->Items->Count; i++)
	{
		names[i] = dynamic_cast<String^>(listBox2->Items[i]);
	}

	// Convert the names to std::string and store them in a std::string array
	msclr::interop::marshal_context context;
	std::string* tels = new std::string[names->Length];
	for (int i = 0; i < names->Length; i++)
	{
		tels[i] = context.marshal_as<std::string>(names[i]);
	}

	// Now you can use the standardStrings array
	quickSort(tels, 0, names->Length - 1);

	// Replace the items in the listBox with the sorted items
	for (int i = 0; i < names->Length; i++)
	{
		listBox2->Items[i] = context.marshal_as<String^>(tels[i]);
	}

		
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//Ord nombre
	// Fill the namevs array with items from listBox1
	array<String^>^ names = gcnew array<String^>(listBox1->Items->Count);
	for (int i = 0; i < listBox1->Items->Count; i++)
	{
		names[i] = dynamic_cast<String^>(listBox1->Items[i]);
	}

	// Convert the names to std::string and store them in a std::string array
	msclr::interop::marshal_context context;
	std::string* standardStrings = new std::string[names->Length];
	for (int i = 0; i < names->Length; i++)
	{
		standardStrings[i] = context.marshal_as<std::string>(names[i]);
	}

	// Now you can use the standardStrings array
	quickSort(standardStrings, 0, names->Length - 1);

	// Replace the items in the listBox with the sorted items
	for (int i = 0; i < names->Length; i++)
	{
		listBox1->Items[i] = context.marshal_as<String^>(standardStrings[i]);
	}

}
		   private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			   // Obtén el índice y el elemento seleccionado en listBox1
			   int selectedIndex = listBox1->SelectedIndex;
			   String^ selectedItem = dynamic_cast<String^>(listBox1->SelectedItem);

			   // Comprueba si el índice es válido en listBox2 y listBox3
			   if (selectedIndex >= 0 && selectedIndex < listBox2->Items->Count && selectedIndex < listBox3->Items->Count) {
				   // Mueve los elementos en listBox2 y listBox3 al mismo índice que en listBox1
				   listBox2->Items->Insert(selectedIndex, listBox2->Items[selectedIndex]);
				   listBox2->Items->RemoveAt(selectedIndex + 1);
				   listBox3->Items->Insert(selectedIndex, listBox3->Items[selectedIndex]);
				   listBox3->Items->RemoveAt(selectedIndex + 1);
			   }
		   }
};
}
