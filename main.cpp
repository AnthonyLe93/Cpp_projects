#include <iostream>
#include <string>

/* Smart pointers */
class Project {
    std::string m_Name;

public:
    void SetName(const std::string &name){
        m_Name = name;
    }
    void ShowProjectDetails()const{
        std::cout << "[Project]" << m_Name << std::endl;
    }

};


class Employee {
    std::unique_ptr<Project> m_pProject{};
public:
    void SetProject(std::unique_ptr<Project> & prj){
        m_pProject = std::move(prj);
    }
    const std::unique_ptr<Project> & GetProject()const {
        return m_pProject;
    }
};

void ShowInfo(const std::unique_ptr<Employee> & emp){
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}

int main() {
    std::unique_ptr<Project> prj {new Project{}};
    prj ->SetName("Video Decoder");
    std::unique_ptr<Employee> e1 {new Employee{}};
    e1 ->SetProject(prj);
    std::unique_ptr<Employee> e2 {new Employee{}};
    e2 ->SetProject(prj);
    std::unique_ptr<Employee> e3 {new Employee{}};
    e3 ->SetProject(prj);

    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();

}