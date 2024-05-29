#include <iostream>
using namespace std;

class Person {
    protected:
        string name;
        int age;
        string gender;
    public:
        Person(string n, int a, string g) : name(n), age(a), gender(g) {}

        virtual void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: " << gender << endl;
        }
};

class Patient : public Person {
    int patientID;
    public:
        Patient(string n, int a, string g, int id) : Person(n, a, g), patientID(id) {}

        void display() {
            cout << "Patient ID: " << patientID << endl;
            Person::display();
        }
};

class Doctor : public Person {
    int doctorID;
    string specialization;
    public:
        Doctor(string n, int a, string g, int id, string s) : Person(n, a, g), doctorID(id), specialization(s) {}

        void display() {
            cout << "Doctor ID: " << doctorID << endl;
            cout << "Specialization: " << specialization << endl;
            Person::display();
        }
};

class Appointment {
    int appointmentID;
    Patient patient;
    Doctor doctor;
    string date;
    string time;
    public:
        Appointment(int id, Patient p, Doctor d, string dt, string tm) : appointmentID(id), patient(p), doctor(d), date(dt), time(tm) {}

        void display() {
            cout << "Appointment ID: " << appointmentID << endl;
            cout << "Date: " << date << endl;
            cout << "Time: " << time << endl;
            patient.display();
            doctor.display();
        }
};

class MedicalRecord {
    int recordID;
    Patient patient;
    string diagnosis;
    string treatment;
    public:
        MedicalRecord(int id, Patient p, string d, string t) : recordID(id), patient(p), diagnosis(d), treatment(t) {}

        void display() {
            cout << "Record ID: " << recordID << endl;
            cout << "Diagnosis: " << diagnosis << endl;
            cout << "Treatment: " << treatment << endl;
            patient.display();
        }
};

int main() {
    Patient p("Amir", 20, "Male", 110);
    Doctor d("Dr. Mubeen", 27, "Male", 112, "Brain specialist");
    Appointment a(132, p, d, "2024-04-14", "10:00 AM");
    MedicalRecord m(204, p, "Hypertension", "Medication and rest");

    cout << "Appointment Details:\n";
    a.display();
    cout << "\nMedical Record Details:\n";
    m.display();

    return 0;
}
