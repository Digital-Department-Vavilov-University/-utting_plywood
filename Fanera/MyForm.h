#include <Windows.h>
#include <string>
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;

// ��������� ��� �������� ���������� � ������
struct Plywood {
    int thickness;
    double price;
    double cuttingPrice;
    double abrisPrice;
};

// ������ � ����������� � ��������� ����� ������
Plywood plywoodTypes[] = {
    { 3, 700, 25, 10 },
    { 4, 800, 30, 20 },
    { 6, 900, 40, 25 },
    { 8, 1000, 50, 35 }
};

// ����� �����
public ref class MyForm : public System::Windows::Forms::Form
{
public:
    MyForm()
    {
        InitializeComponent();
    }

private:
    System::Windows::Forms::ComboBox^ plywoodComboBox;
    System::Windows::Forms::TextBox^ lengthTextBox;
    System::Windows::Forms::TextBox^ abrisTextBox;
    System::Windows::Forms::CheckBox^ ownMaterialCheckBox;
    System::Windows::Forms::Label^ priceLabel;
    System::Windows::Forms::Label^ operatorFeeLabel;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
       System::Windows::Forms::Button^ calculateButton;

    // ���������� ������� ������� ������ "����������"
    void calculateButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // �������� ��������� ������ ������
        int selectedIndex = plywoodComboBox->SelectedIndex;

        // �������� ���������� � ��������� ������
        Plywood selectedPlywood = plywoodTypes[selectedIndex];

        // �������� �� ������ ����
        if (lengthTextBox->Text->Length == 0 || abrisTextBox->Text->Length == 0) {
            MessageBox::Show("����������, ������� ����� ����� � ������.");
            return;
        }

        // ������� � �������������� TryParse:
        double cuttingLength;
        if (Double::TryParse(lengthTextBox->Text, cuttingLength)) {
            // ��������� ���� �����
            double cuttingPrice = selectedPlywood.cuttingPrice * cuttingLength;

            double abrisLength;
            if (Double::TryParse(abrisTextBox->Text, abrisLength)) {
                // ��������� ���� ������
                double abrisPrice = selectedPlywood.abrisPrice * abrisLength;

                // ��������� ����� ���������
                double totalPrice = selectedPlywood.price + cuttingPrice + abrisPrice;

                // ���� ������� ����� "���� ��������", �� ������� ��������� ������
                if (ownMaterialCheckBox->Checked)
                {
                    totalPrice -= selectedPlywood.price;
                }

                // ��������� �������� ���� � �����
                priceLabel->Text = "���������: " + totalPrice.ToString() + " ���.";

                // ��������� ��������� ��������� ������
                double operatorFee = totalPrice * 0.15;

                // ��������� �������� �������� ��������� � �����
                operatorFeeLabel->Text = "�������� ���������: " + operatorFee.ToString() + " ���.";
            }
            else {
                MessageBox::Show("�������� ������ ����� ������. ������� �����.");
                return;
            }
        }
        else {
            MessageBox::Show("�������� ������ ����� �����. ������� �����.");
            return;
        }
    }

    // ������������� ����������� �����
    void InitializeComponent()
    {
        this->plywoodComboBox = (gcnew System::Windows::Forms::ComboBox());
        this->lengthTextBox = (gcnew System::Windows::Forms::TextBox());
        this->abrisTextBox = (gcnew System::Windows::Forms::TextBox());
        this->ownMaterialCheckBox = (gcnew System::Windows::Forms::CheckBox());
        this->priceLabel = (gcnew System::Windows::Forms::Label());
        this->operatorFeeLabel = (gcnew System::Windows::Forms::Label());
        this->calculateButton = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
        // 
        // plywoodComboBox
        // 
        this->plywoodComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->plywoodComboBox->FormattingEnabled = true;
        this->plywoodComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"3 ��", L"4 ��", L"6 ��", L"8 ��" });
        this->plywoodComboBox->Location = System::Drawing::Point(189, 85);
        this->plywoodComboBox->Name = L"plywoodComboBox";
        this->plywoodComboBox->Size = System::Drawing::Size(147, 21);
        this->plywoodComboBox->TabIndex = 0;
        // 
        // lengthTextBox
        // 
        this->lengthTextBox->Location = System::Drawing::Point(189, 135);
        this->lengthTextBox->Name = L"lengthTextBox";
        this->lengthTextBox->Size = System::Drawing::Size(147, 20);
        this->lengthTextBox->TabIndex = 1;
        // 
        // abrisTextBox
        // 
        this->abrisTextBox->Location = System::Drawing::Point(189, 191);
        this->abrisTextBox->Name = L"abrisTextBox";
        this->abrisTextBox->Size = System::Drawing::Size(147, 20);
        this->abrisTextBox->TabIndex = 2;
        // 
        // ownMaterialCheckBox
        // 
        this->ownMaterialCheckBox->Location = System::Drawing::Point(18, 12);
        this->ownMaterialCheckBox->Name = L"ownMaterialCheckBox";
        this->ownMaterialCheckBox->Size = System::Drawing::Size(156, 50);
        this->ownMaterialCheckBox->TabIndex = 3;
        this->ownMaterialCheckBox->Text = L"��������, ���� ����������� ���� ��������";
        this->ownMaterialCheckBox->UseVisualStyleBackColor = true;
        // 
        // priceLabel
        // 
        this->priceLabel->Location = System::Drawing::Point(15, 315);
        this->priceLabel->Name = L"priceLabel";
        this->priceLabel->Size = System::Drawing::Size(100, 23);
        this->priceLabel->TabIndex = 4;
        this->priceLabel->Text = L"���������: 0 ���.";
        // 
        // operatorFeeLabel
        // 
        this->operatorFeeLabel->Location = System::Drawing::Point(15, 338);
        this->operatorFeeLabel->Name = L"operatorFeeLabel";
        this->operatorFeeLabel->Size = System::Drawing::Size(150, 23);
        this->operatorFeeLabel->TabIndex = 5;
        this->operatorFeeLabel->Text = L"�������� ���������: 0 ���.";
        // 
        // calculateButton
        // 
        this->calculateButton->Location = System::Drawing::Point(62, 262);
        this->calculateButton->Name = L"calculateButton";
        this->calculateButton->Size = System::Drawing::Size(156, 32);
        this->calculateButton->TabIndex = 6;
        this->calculateButton->Text = L"����������";
        this->calculateButton->UseVisualStyleBackColor = true;
        this->calculateButton->Click += gcnew System::EventHandler(this, &MyForm::calculateButton_Click);
        // 
        // label1
        // 
        this->label1->Location = System::Drawing::Point(15, 135);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(147, 20);
        this->label1->TabIndex = 7;
        this->label1->Text = L"������� ����� ����� (�)";
        // 
        // label2
        // 
        this->label2->Location = System::Drawing::Point(15, 191);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(147, 20);
        this->label2->TabIndex = 8;
        this->label2->Text = L"������� ����� ������ (�)";
        // 
        // label3
        // 
        this->label3->Location = System::Drawing::Point(15, 85);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(178, 20);
        this->label3->TabIndex = 9;
        this->label3->Text = L"�������� ������� ������ (��)";
        // 
        // MyForm
        // 
        this->ClientSize = System::Drawing::Size(348, 405);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->calculateButton);
        this->Controls->Add(this->operatorFeeLabel);
        this->Controls->Add(this->priceLabel);
        this->Controls->Add(this->ownMaterialCheckBox);
        this->Controls->Add(this->abrisTextBox);
        this->Controls->Add(this->lengthTextBox);
        this->Controls->Add(this->plywoodComboBox);
        this->Name = L"MyForm";
        this->ResumeLayout(false);
        this->PerformLayout();

    }
};

// ������� ������� ���������
