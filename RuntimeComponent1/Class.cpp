#include "pch.h"
#include "Class.h"
#include "Class.g.cpp"

namespace winrt::RuntimeComponent1::implementation
{
    int32_t Class::MyProperty()
    {
        return m_value;
    }

    void Class::MyProperty(int32_t value)
    {
        if (m_value != value)
        {
            m_value = value;
            if (m_propertyChanged)
                m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs(L"MyProperty"));
        }
    }

    winrt::event_token Class::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void Class::PropertyChanged(winrt::event_token const& token)
    {
        m_propertyChanged.remove(token);
    }
}
