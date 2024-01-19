#ifndef BRAIN_HPP
# define BRAIN_HPP

# include	<iostream>
# include	<sstream>

class Brain {
 private:
	std::string _ideas[100];
 public:
	//OCCF
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain(void);
	//method
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);
};

#endif