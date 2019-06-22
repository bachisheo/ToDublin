#pragma once 
namespace airport {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary> 
	/// Сводка для game 
	/// </summary> 
	public ref class game : public System::Windows::Forms::Form
	{
	public:
		int in_cloud = 0;
		float speed;
		int score;
		ref struct dir_plane {
			bool right, left, down, up;
		} where_plane;
		int is_start = 0;
		int size_plane, widht_cloud, height_cloud;
	private: System::Windows::Forms::Panel^ health_bar;
	public:
	private: System::Windows::Forms::PictureBox^ green_health;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label4;
			 array<int, 2> ^ cloud_xy_coord = gcnew array<int, 2>(9, 2);
			 int loc_x;
			 int loc_y;
			 void promotion(int x, int y) {
				 if ((loc_x == 0 && x > 0) || (loc_x == (this->Width - 100) && x < 0) || (loc_x > 0 && loc_x < (this->Width - 100)))
					 loc_x += x;
				 if ((loc_y == 400 && y < 0) || (loc_y == 0 && y > 0) || (loc_y > 0 && loc_y < 400))
					 loc_y += y;
			 }
			 Bitmap^ cloud;
			 Bitmap^ plane;

	private: System::Windows::Forms::Button^ game_button;
	private: System::Windows::Forms::Button^ rec_button;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ score_text;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ count;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ minus300;

	private: System::Windows::Forms::Button^ right_button;
	private: System::Windows::Forms::Timer^ timer1;
	public:
		game(void)
		{
			InitializeComponent();
			// 
			//TODO: добавьте код конструктора 
			// 
			SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::AllPaintingInWmPaint | ControlStyles::UserPaint, true);
			UpdateStyles();
		}
	protected:
		/// <summary> 
		/// Освободить все используемые ресурсы. 
		/// </summary> 
		~game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary> 
		/// Обязательная переменная конструктора. 
		/// </summary> 
#pragma region Windows Form Designer generated code 
/// <summary> 
/// Требуемый метод для поддержки конструктора — не изменяйте 
/// содержимое этого метода с помощью редактора кода. 
/// </summary> 
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->game_button = (gcnew System::Windows::Forms::Button());
			this->rec_button = (gcnew System::Windows::Forms::Button());
			this->right_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->score_text = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->minus300 = (gcnew System::Windows::Forms::Label());
			this->health_bar = (gcnew System::Windows::Forms::Panel());
			this->green_health = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->health_bar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->green_health))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &game::Timer1_Tick);
			// 
			// game_button
			// 
			this->game_button->BackColor = System::Drawing::Color::Azure;
			this->game_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->game_button->FlatAppearance->BorderSize = 0;
			this->game_button->Font = (gcnew System::Drawing::Font(L"Sylfaen", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->game_button->ForeColor = System::Drawing::Color::DarkBlue;
			this->game_button->Location = System::Drawing::Point(275, 139);
			this->game_button->Name = L"game_button";
			this->game_button->Size = System::Drawing::Size(190, 64);
			this->game_button->TabIndex = 0;
			this->game_button->Text = L"Играть";
			this->game_button->UseVisualStyleBackColor = false;
			this->game_button->Click += gcnew System::EventHandler(this, &game::Game_button_Click);
			// 
			// rec_button
			// 
			this->rec_button->BackColor = System::Drawing::Color::Azure;
			this->rec_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->rec_button->FlatAppearance->BorderSize = 0;
			this->rec_button->Font = (gcnew System::Drawing::Font(L"Sylfaen", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rec_button->ForeColor = System::Drawing::Color::DarkBlue;
			this->rec_button->Location = System::Drawing::Point(275, 316);
			this->rec_button->Name = L"rec_button";
			this->rec_button->Size = System::Drawing::Size(190, 64);
			this->rec_button->TabIndex = 1;
			this->rec_button->Text = L"Рекорды";
			this->rec_button->UseVisualStyleBackColor = false;
			this->rec_button->Click += gcnew System::EventHandler(this, &game::Rec_button_Click);
			// 
			// right_button
			// 
			this->right_button->BackColor = System::Drawing::Color::Azure;
			this->right_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->right_button->FlatAppearance->BorderSize = 0;
			this->right_button->Font = (gcnew System::Drawing::Font(L"Sylfaen", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->right_button->ForeColor = System::Drawing::Color::DarkBlue;
			this->right_button->Location = System::Drawing::Point(275, 227);
			this->right_button->Name = L"right_button";
			this->right_button->Size = System::Drawing::Size(190, 64);
			this->right_button->TabIndex = 2;
			this->right_button->Text = L"Правила";
			this->right_button->UseVisualStyleBackColor = false;
			this->right_button->Click += gcnew System::EventHandler(this, &game::Right_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sylfaen", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Navy;
			this->label1->Location = System::Drawing::Point(112, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(433, 84);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Пилотируйте свой самолёт \r\n\"To Dublin\"!";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// score_text
			// 
			this->score_text->AutoSize = true;
			this->score_text->BackColor = System::Drawing::Color::Transparent;
			this->score_text->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->score_text->ForeColor = System::Drawing::Color::Navy;
			this->score_text->Location = System::Drawing::Point(22, 32);
			this->score_text->Name = L"score_text";
			this->score_text->Size = System::Drawing::Size(18, 19);
			this->score_text->TabIndex = 4;
			this->score_text->Text = L"0";
			this->score_text->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(304, 407);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(130, 134);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::LightSkyBlue;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->count,
					this->name, this->time
			});
			this->dataGridView1->GridColor = System::Drawing::Color::Navy;
			this->dataGridView1->Location = System::Drawing::Point(121, 139);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->RowTemplate->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(497, 262);
			this->dataGridView1->TabIndex = 6;
			this->dataGridView1->Visible = false;
			// 
			// count
			// 
			this->count->FillWeight = 44.73458F;
			this->count->HeaderText = L"Счет";
			this->count->MinimumWidth = 6;
			this->count->Name = L"count";
			// 
			// name
			// 
			this->name->FillWeight = 80.21391F;
			this->name->HeaderText = L"Игрок";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			// 
			// time
			// 
			this->time->FillWeight = 175.0515F;
			this->time->HeaderText = L"Дата и время";
			this->time->MinimumWidth = 6;
			this->time->Name = L"time";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(546, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 29);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &game::Button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Navy;
			this->label2->Location = System::Drawing::Point(119, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 18);
			this->label2->TabIndex = 8;
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label2->Visible = false;
			// 
			// minus300
			// 
			this->minus300->AutoSize = true;
			this->minus300->BackColor = System::Drawing::Color::Transparent;
			this->minus300->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minus300->ForeColor = System::Drawing::Color::Red;
			this->minus300->Location = System::Drawing::Point(502, 13);
			this->minus300->Name = L"minus300";
			this->minus300->Size = System::Drawing::Size(43, 18);
			this->minus300->TabIndex = 9;
			this->minus300->Text = L"-300!";
			this->minus300->Visible = false;
			// 
			// health_bar
			// 
			this->health_bar->BackColor = System::Drawing::Color::Transparent;
			this->health_bar->Controls->Add(this->green_health);
			this->health_bar->Controls->Add(this->pictureBox2);
			this->health_bar->Controls->Add(this->label4);
			this->health_bar->Location = System::Drawing::Point(0, 524);
			this->health_bar->Name = L"health_bar";
			this->health_bar->Size = System::Drawing::Size(169, 27);
			this->health_bar->TabIndex = 10;
			this->health_bar->Visible = false;
			// 
			// green_health
			// 
			this->green_health->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->green_health->Location = System::Drawing::Point(63, 7);
			this->green_health->Name = L"green_health";
			this->green_health->Size = System::Drawing::Size(100, 13);
			this->green_health->TabIndex = 12;
			this->green_health->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::DarkRed;
			this->pictureBox2->Location = System::Drawing::Point(63, 7);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 13);
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::Color::Navy;
			this->label4->Location = System::Drawing::Point(3, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 18);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Здоровье";
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSkyBlue;
			this->ClientSize = System::Drawing::Size(732, 553);
			this->Controls->Add(this->health_bar);
			this->Controls->Add(this->minus300);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->score_text);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->right_button);
			this->Controls->Add(this->rec_button);
			this->Controls->Add(this->game_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->KeyPreview = true;
			this->Name = L"game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ToDublin";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &game::Game_FormClosing);
			this->Load += gcnew System::EventHandler(this, &game::Game_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &game::Game_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &game::Game_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &game::Game_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->health_bar->ResumeLayout(false);
			this->health_bar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->green_health))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 
	private: System::Void Game_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		promotion(0, 0);
		Graphics^ g = e->Graphics;
		//отрисовка самолёта 
		g->DrawImage(plane, Rectangle(loc_x, loc_y, size_plane, size_plane));
		//отрисовка облака 
		for (int i = 0; i < 9; i++)
		{
			g->DrawImage(cloud, Rectangle(cloud_xy_coord[i, 0], cloud_xy_coord[i, 1], widht_cloud, height_cloud));

		}

	}
	private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		score_text->Text = Convert::ToString(Convert::ToInt32(score_text->Text) + 1);
		Refresh();
		move_object();
		if (Convert::ToInt32(score_text->Text) % 300 == 0)
			speed += 0.5;

	}
	private: System::Void Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right: where_plane.right = 1; break;
		case Keys::Left: where_plane.left = 1; break;
		case Keys::Down: where_plane.down = 1; break;
		case Keys::Up: where_plane.up = 1; break;
		}
	}
	private: System::Void Game_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Right: where_plane.right = 0; break;
		case Keys::Left: where_plane.left = 0; break;
		case Keys::Down: where_plane.down = 0; break;
		case Keys::Up: where_plane.up = 0; break;
		}
	}
	private: void setup() {
		in_cloud = 0;
		speed = 2;
		timer1->Start();
		score_text->Text = Convert::ToString(1);
		size_plane = 100;
		height_cloud = 75;
		widht_cloud = 120;
		loc_x = 320;
		loc_y = 400;
		where_plane.up = 0;
		where_plane.down = 0;
		where_plane.left = 0;
		where_plane.right = 0;
		cloud_xy_coord[0, 1] = -100;
		cloud_xy_coord[0, 0] = 20;
		cloud_xy_coord[1, 1] = -100;
		cloud_xy_coord[1, 0] = 220;
		cloud_xy_coord[2, 1] = -100;
		cloud_xy_coord[2, 0] = 520;
		cloud_xy_coord[3, 1] = -330;
		cloud_xy_coord[3, 0] = 120;
		cloud_xy_coord[4, 1] = -330;
		cloud_xy_coord[4, 0] = 270;
		cloud_xy_coord[5, 1] = -330;
		cloud_xy_coord[5, 0] = 320;
		cloud_xy_coord[6, 1] = -580;
		cloud_xy_coord[6, 0] = 20;
		cloud_xy_coord[7, 1] = -580;
		cloud_xy_coord[7, 0] = 120;
		cloud_xy_coord[8, 1] = -580;
		cloud_xy_coord[8, 0] = 620;
		green_health->Width = 100;
		health_bar->Show();
	}
	private: void game_over() {
		is_start = false;
		score = Convert::ToInt32(score_text->Text) / 10;
		timer1->Stop();
		//make_new_pass^ new_rec = gcnew make_new_pass();
		////изменяем свойства вызываемой формы для записи рекордов 
		//new_rec->is_pass = false;
		//new_rec->name_file = "record.txt";
		//new_rec->label2->Text = "Вы набрали " + score + " очков!\nВведите своё имя:";
		//new_rec->label2->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		   // static_cast<System::Byte>(204)));
		//new_rec->Text = "Добавление рекорда";
		//new_rec->save_pass_button->Text = "Добавить";
		//new_rec->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		   // static_cast<System::Byte>(204)));
		//new_rec->save_pass_button->Font = (gcnew System::Drawing::Font(L"Sylfaen", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		   // static_cast<System::Byte>(204)));
		//new_rec->save_pass_button->Show();
		//new_rec->label1->Text = "Результат добавлен!";
		//new_rec->score = score;
		//new_rec->maskedTextBox1->Visible = true;
		//new_rec->new_pass_textBox->Visible = false;
		//new_rec->Show();
		//new_rec->Owner = this;
		game_button->Show();
		right_button->Show();
		rec_button->Show();
		label1->Show();
		score_text->Hide();
		health_bar->Hide();
	}
	private: void move_object() {
		Random rnd;
		for (int i = 0; i < 9; i++) {
			//проверка на встречу крыла самолёта с облаком по OY 
			if ((loc_y + size_plane * 0.4 - cloud_xy_coord[i, 1]) > 0 && (loc_y + size_plane * 0.6 - ((cloud_xy_coord[i, 1]) + height_cloud)) < 0) {
				//слева 
				if ((loc_x - cloud_xy_coord[i, 0]) > 0 && (loc_x - (cloud_xy_coord[i, 0] + widht_cloud)) < 0) {
					if (!in_cloud) {
						minus300->Location = Point(loc_x - 50, loc_y);
						minus300->Visible = true;
						score_text->Text = Convert::ToString(Convert::ToInt32(score_text->Text) - 300);
						in_cloud = i + 1;
					}
					else {
						green_health->Width--;
					}
				}
				//справа 
				if ((cloud_xy_coord[i, 0] - loc_x) < size_plane && (cloud_xy_coord[i, 0] - loc_x) > 0) {
					if (!in_cloud) {
						minus300->Location = Point(loc_x + 100, loc_y);
						minus300->Visible = true;
						score_text->Text = Convert::ToString(Convert::ToInt32(score_text->Text) - 300);
						in_cloud = i + 1;
					}
					else {
						green_health->Width--;
					}
				}
			}
			else if (i + 1 == in_cloud) {
				in_cloud = 0;
				minus300->Visible = false;
			}
			//проверка на встречу облака и самолёта 
			if ((loc_x + size_plane * 0.7 - cloud_xy_coord[i, 0]) > 0 && (loc_x + size_plane * 0.3 - (cloud_xy_coord[i, 0] + widht_cloud)) < 0 && (loc_y - cloud_xy_coord[i, 1]) > size_plane * -0.9 && (loc_y + size_plane * 0.9 - ((cloud_xy_coord[i, 1]) + height_cloud)) < size_plane * 0.9) {
				green_health->Width--;
			}
			//возврат ушедшего облака с экрана на начало
			if (cloud_xy_coord[i, 1] > 600) { //проверка на выход облака за границы 
				cloud_xy_coord[i, 1] = -100; //возвращаем у-координату облака в начало 
				cloud_xy_coord[i, 0] = rnd.Next(650); //задаем рандомную х-координату облака 
			}
			//движение облака
			cloud_xy_coord[i, 1] += speed;
		}
		//проверка здоровья
		if (green_health->Width == 0) {
			game_over();
		}
		//направления движения самолета
		int v_plane = 5;
		if (where_plane.up)
			promotion(0, -v_plane);
		if (where_plane.down)
			promotion(0, v_plane);
		if (where_plane.left)
			promotion(-v_plane, 0);
		if (where_plane.right)
			promotion(v_plane, 0);
	}

	private: System::Void Game_button_Click(System::Object^ sender, System::EventArgs^ e) {
		is_start = true;
		if (is_start) {
			setup();
			game_button->Hide();
			right_button->Hide();
			rec_button->Hide();
			label1->Hide();
			score_text->Show();
			pictureBox1->Hide();
		}
	}
	private: System::Void Right_button_Click(System::Object^ sender, System::EventArgs^ e) {
		game_button->Hide();
		rec_button->Hide();
		right_button->Hide();
		button1->Show();
		label2->Show();
		dataGridView1->Hide();
	}
	private: System::Void Rec_button_Click(System::Object^ sender, System::EventArgs^ e) {
		game_button->Hide();
		rec_button->Hide();
		right_button->Hide();
		button1->Visible = true;
		dataGridView1->Visible = true;
		if (!IO::File::Exists("record.txt")) {
			StreamWriter^ fps = gcnew StreamWriter("record.txt", true);
			fps->Close();
			label2->Text = "\n\n\nВ таблице пока нет рекордов!";
			label2->Visible = true;
		}
		StreamReader^ str = gcnew StreamReader("record.txt");
		String^ buf_string;
		dataGridView1->Rows->Clear();
		for (int i = 0; !str->EndOfStream; i++) {
			dataGridView1->Rows->Add();
			buf_string = str->ReadLine();
			cli::array<String^>^ cells_fill;
			cells_fill = buf_string->Split('|');
			for (int j = 0; j < 3; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = cells_fill[j];
			}
		}
		str->Close();

	}
	private: System::Void Game_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		timer1->Stop();
	}

	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Visible = false;
		button1->Visible = false;
		label2->Visible = false;
		game_button->Show();
		rec_button->Show();
		right_button->Show();
	}
	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			cloud = gcnew Bitmap("cloud.png");
			plane = gcnew Bitmap("plane.png");
		}
		catch (System::Exception^ ex) {
			MessageBox::Show("Файл формата \"png\" не найден", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Close();
		}
	}
	};
}
