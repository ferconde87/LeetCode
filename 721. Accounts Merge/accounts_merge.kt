  fun accountsMerge(accounts: List<List<String>>): List<List<String>> {
    val emailsToParentIds : MutableMap<String, Int> = mutableMapOf()
    val parents : IntArray = IntArray(accounts.size) { it }

    fun root(id: Int) : Int {
      var root = id
      while(root != parents[root]) {
        root = parents[parents[root]]
      }
      return root
    }

    fun union(p: Int, q: Int) {
      val i = root(p)
      val j = root(q)
      parents[i] = j
    }

    for ((id, account) in accounts.withIndex()) {
      for (email in account.subList(1, account.size)) {
        if (emailsToParentIds.containsKey(email)) {
          union(id, emailsToParentIds[email]!!)
        } else {
          emailsToParentIds[email] = id
        }
      }
    }

    var result : MutableMap<Int, MutableList<String>> = mutableMapOf()
    for ((email, id) in emailsToParentIds) {
      var root = root(id)
      if (result.containsKey(root)) {
        result.getValue(root) += email
      } else {
        result[root] = mutableListOf(email)
      }
    }
    
    result.map{ (_, values) -> values.sort()}

    return result.map { (key, value) ->
      value.add(0, accounts[key][0])
      value
    }
  }
