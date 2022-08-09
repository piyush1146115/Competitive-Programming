class LRUCache {
public:
    int m_capacity;
    map<int, list<pair<int,int>>::iterator> m_map;
    list<pair<int,int>> m_list;
    
    LRUCache(int capacity) {
        m_capacity = capacity;    
    }
    
    int get(int key) {
        auto found_iter = m_map.find(key);
        if(found_iter == m_map.end())
            return -1;
        
        m_list.splice(m_list.begin(), m_list, found_iter->second);
        
        return found_iter->second->second;
        
    }
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        
        
        if(found_iter != m_map.end()){
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            found_iter->second->second = value;
            return;
        }
        
        if(m_map.size() == m_capacity){
            int key_to_del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_del);
        }
        
         m_list.emplace_front(key, value);
         m_map[key] = m_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */