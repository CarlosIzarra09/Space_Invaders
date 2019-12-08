#pragma once
#include "Game.hpp"
#include "SaveScore.hpp"
#include <functional>



namespace SpaceInvaders {
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		

		System::Drawing::Image^imgP;
		System::Drawing::Image^imgB;
		System::Drawing::Image^imgFondo;
		System::Drawing::Image^imgFondo2;
		System::Drawing::Image^imgNAVE1;
		System::Drawing::Image^imgNAVE2;
		System::Drawing::Image^imgNAVE3;
		System::Drawing::Image^imgNAVE4;
		System::Drawing::Image^imgBenem;
		System::Drawing::Image^imgButton11;
		System::Drawing::Image^imgButton12;
		System::Drawing::Image^imgButton2;
		System::Drawing::Image^imgNodriza;
		Game*juego;
		SaveScore*Read_Write;
		System::Media::SoundPlayer ^music;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Timer^  timer1;
			
		 
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			juego = new Game();
			Read_Write = new SaveScore();
			juego->Init(3);
			imgB = gcnew System::Drawing::Bitmap("../bitmaps/bala.png");
			imgP = gcnew System::Drawing::Bitmap("../bitmaps/navecita.png");
			imgFondo = gcnew System::Drawing::Bitmap("../bitmaps/invaders.png");
			imgFondo2 = gcnew System::Drawing::Bitmap("../bitmaps/invaders2.png");
			imgNAVE1 = gcnew System::Drawing::Bitmap("../bitmaps/nave1.png");
			imgNAVE2 = gcnew System::Drawing::Bitmap("../bitmaps/nave2.png");
			imgNAVE3 = gcnew System::Drawing::Bitmap("../bitmaps/nave3.png");
			imgNAVE4 = gcnew System::Drawing::Bitmap("../bitmaps/nave4.png");
			imgBenem = gcnew System::Drawing::Bitmap("../bitmaps/balaenemiga.png");
			imgButton11 = gcnew System::Drawing::Bitmap("../bitmaps/playmusic.png");
			imgButton12 = gcnew System::Drawing::Bitmap("../bitmaps/stopmusic.png");
			imgButton2 = gcnew System::Drawing::Bitmap("../bitmaps/save.png");
			imgNodriza = gcnew System::Drawing::Bitmap("../bitmaps/nodriza.png");
			music = gcnew System::Media::SoundPlayer("../bitmaps/spaceinvaders1.wav");
			music->PlayLooping();
			(((Bitmap^)imgP)->MakeTransparent(((Bitmap^)imgP)->GetPixel(0, 0)));
			(((Bitmap^)imgB)->MakeTransparent(((Bitmap^)imgB)->GetPixel(0, 0)));
			(((Bitmap^)imgNAVE1)->MakeTransparent(((Bitmap^)imgNAVE1)->GetPixel(0, 0)));
			(((Bitmap^)imgNAVE2)->MakeTransparent(((Bitmap^)imgNAVE2)->GetPixel(0, 0)));
			(((Bitmap^)imgNAVE3)->MakeTransparent(((Bitmap^)imgNAVE3)->GetPixel(0, 0)));
			(((Bitmap^)imgNAVE4)->MakeTransparent(((Bitmap^)imgNAVE4)->GetPixel(0, 0)));
			(((Bitmap^)imgNodriza)->MakeTransparent(((Bitmap^)imgNodriza)->GetPixel(0, 0)));
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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 60;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader2 });
			this->listView1->Font = (gcnew System::Drawing::Font(L"Space Invaders", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->ForeColor = System::Drawing::Color::White;
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(315, 153);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(627, 465);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->Visible = false;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"NAME";
			this->columnHeader1->Width = 302;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"SCORE";
			this->columnHeader2->Width = 317;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Space Invaders", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(492, 77);
			this->textBox1->MaxLength = 14;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(312, 38);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Space Invaders", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(309, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 33);
			this->label1->TabIndex = 2;
			this->label1->Text = L"your name";
			this->label1->Visible = false;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Space Invaders", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(810, 77);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"SAVE";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(12, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 49);
			this->button2->TabIndex = 4;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listView1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);

				

		juego->Play(buffer->Graphics, imgP,imgB, imgNAVE1, imgNAVE2,imgNAVE3,imgNAVE4,imgBenem,imgButton11,imgButton12, imgButton2,imgNodriza,imgFondo,imgFondo2);
		
				

		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (juego->Retornar_vidas() > 0)
		{
			switch (e->KeyCode)
			{
			case Keys::Left:juego->Retornar_jugador()->Mover_Izquierda(CreateGraphics()); break;
			case Keys::Right:juego->Retornar_jugador()->Mover_Derecha(CreateGraphics()); break;
			case Keys::Up:juego->Retornar_jugador()->Disparar(); break;
			}
		}

		if (e->KeyCode == Keys::R)
		{
			
			juego->Retornar_Nodrizas()->eliminar_pos(0);
			while (juego->Retornar_ArrNaves()->Cant_naves() != 0)
			{
				juego->Retornar_ArrNaves()->eliminar_pos(0);
			}
	
			
			
			juego->Init(0);
		}

	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	if (juego->colision_mouse(juego->retornar_Boton1(), e->X, e->Y) || juego->colision_mouse(juego->retornar_Boton2(), e->X, e->Y))
	{
		Cursor->Current = Cursors::Hand;
	}
	//else Cursor->Current = Cursors::Default;
}
private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	if (juego->colision_mouse(juego->retornar_Boton1(), e->X, e->Y))
	{
		juego->retornar_Boton1()->Cambiar_ID(juego->retornar_Boton1()->Retornar_ID() + 1);
		if (juego->retornar_Boton1()->Retornar_ID() %2!=0)
			music->PlayLooping();
		else music->Stop();
	}

	if (juego->colision_mouse(juego->retornar_Boton2(), e->X, e->Y))
	{
		juego->Cambiar_TableScore(true);

		label1->Visible = true;
		textBox1->Visible = true;
		button1->Visible = true;
		button2->Visible = true;
		

		label1->Enabled = true;
		textBox1->Enabled = true;
		button1->Enabled = true;
		button2->Enabled = true;
		listView1->Enabled = true;

		
		textBox1->Focus();
	
	}

}

private: void bubbleSort(vector<Registro*>&aux)
{
	for (int i = 0; i < aux.size() - 1; i++)
	{
		for (int j = 0; j < aux.size() - i - 1; j++)
		{
			if (aux[j]->Retornar_Score() < aux[j + 1]->Retornar_Score())
				swap(aux[j], aux[j + 1]);
		}
	}
}


private: void MarshalString(String ^ s, string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}


	

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	vector<Registro*>arreglo;
	//auto l1 = [](Registro*a) {return a->Retornar_Score(); };
	string temp;
	MarshalString(textBox1->Text, temp);

	Read_Write->Write(temp, juego->Retornar_Puntos());
	Read_Write->Read(arreglo);

	if (arreglo.size() > 1)
		bubbleSort(arreglo);

	Read_Write->Limpiar_Archivo();

	
	//listView1->Enabled = true;
	listView1->Visible = true;
	textBox1->Enabled = false;
	

	String ^name;
	ListViewItem^Item;


	for (auto it : arreglo)
	{
		Read_Write->Write(it->Retornar_Nombre(), it->Retornar_Score());

		name = gcnew String(it->Retornar_Nombre().c_str());

		Item = gcnew ListViewItem(name);
		if (Item->Text == textBox1->Text)
			Item->ForeColor = System::Drawing::Color::Aqua;

		Item->SubItems->Add(it->Retornar_Score().ToString());
		listView1->Items->Add(Item);
	}

	

	button1->Enabled = false;
	arreglo.clear();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	juego->Cambiar_TableScore(false);
	label1->Visible = false;
	textBox1->Visible = false;
	button1->Visible = false;
	button2->Visible = false;
	listView1->Visible = false;


	label1->Enabled = false;
	textBox1->Enabled =false;
	button1->Enabled = false;
	button2->Enabled = false;
	listView1->Enabled = false;

	textBox1->Text = "";
	listView1->Items->Clear();

	juego->Retornar_Nodrizas()->eliminar_pos(0);
	while (juego->Retornar_ArrNaves()->Cant_naves() != 0)
	{
		juego->Retornar_ArrNaves()->eliminar_pos(0);
	}
	
	juego->Init(0);
}
};
}
