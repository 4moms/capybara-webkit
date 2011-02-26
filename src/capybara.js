Capybara = {
  nextIndex: 0,
  nodes: {},

  invoke: function () {
    return this[CapybaraInvocation.functionName].apply(this, CapybaraInvocation.arguments);
  },

  find: function (xpath) {
    var iterator = document.evaluate(xpath, document, null, XPathResult.ORDERED_NODE_ITERATOR_TYPE, null);
    var node;
    var results = [];
    while (node = iterator.iterateNext()) {
      this.nextIndex++;
      this.nodes[this.nextIndex] = node;
      results.push(this.nextIndex);
    }
    return results.join(",");
  },

  text: function (index) {
    return this.nodes[index].innerText;
  },

  attribute: function (index, name) {
    return this.nodes[index].getAttribute(name);
  },

  tagName: function(index) {
    return this.nodes[index].tagName.toLowerCase();
  },

  value: function(index) {
    return this.nodes[index].value;
  }

};

